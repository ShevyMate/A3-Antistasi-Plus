//if (!isServer) exitWith{};

if (player != leader group player) exitWith {hint "You cannot dismiss anyone if you are not the squad leader"};

private ["_units","_hr","_resourcesFIA","_unit","_newGroup"];

_units = _this select 0;
_units = _units - [player];
_units = _units select {!(isPlayer _x)};
if (_units isEqualTo []) exitWith {};
if (_units findIf {!([_x] call A3A_fnc_canFight)} != -1) exitWith {hint "You cannot disband supressed, undercover or unconscious units"};
player globalChat "Get out of my sight you useless scum!";

_newGroup = createGroup buenos;
//if ({isPlayer _x} count units group player == 1) then {_ai = true; _newGroup = createGroup buenos};

{
if (typeOf _x != SDKUnarmed) then
	{
	[_x] join _newGroup;
	if !(hayIFA) then {arrayids = arrayids + [name _x]};
	};
} forEach _units;

if (recruitCooldown < time) then {recruitCooldown = time + 60} else {recruitCooldown = recruitCooldown + 60};


_lider = leader _newGroup;

{_x domove getMarkerPos respawnTeamPlayer} forEach units _newGroup;

_tiempo = time + 120;

waitUntil {sleep 1; (time > _tiempo) or ({(_x distance getMarkerPos respawnTeamPlayer < 50) and (alive _x)} count units _newGroup == {alive _x} count units _newGroup)};

_hr = 0;
_resourcesFIA = 0;
_items = [];
_ammunition = [];
_armas = [];

{_unit = _x;
if ([_unit] call A3A_fnc_canFight) then
	{
	_resourcesFIA = _resourcesFIA + (server getVariable (typeOf _unit));
	_hr = _hr +1;
	{if (not(([_x] call BIS_fnc_baseWeapon) in unlockedWeapons)) then {_armas pushBack ([_x] call BIS_fnc_baseWeapon)}} forEach weapons _unit;
	{if (not(_x in unlockedMagazines)) then {_ammunition pushBack _x}} forEach magazines _unit;
	_items = _items + (items _unit) + (primaryWeaponItems _unit) + (assignedItems _unit) + (secondaryWeaponItems _unit) + [(hmd _unit),(headGear _unit),(vest _unit)];
	};
deleteVehicle _x;
} forEach units _newGroup;
if (!isMultiplayer) then {_nul = [_hr,_resourcesFIA] remoteExec ["A3A_fnc_resourcesFIA",2];} else {_nul = [_hr,0] remoteExec ["A3A_fnc_resourcesFIA",2]; [_resourcesFIA] call A3A_fnc_resourcesPlayer};
{caja addWeaponCargoGlobal [_x,1]} forEach _armas;
{caja addMagazineCargoGlobal [_x,1]} forEach _ammunition;
{caja addItemCargoGlobal [_x,1]} forEach _items;
deleteGroup _newGroup;


