params ["_traderX"];

_traderX addAction [
	localize "STR_antistasi_actions_common_access_vehicle_marker_text", 
	{call SCRT_fnc_trader_tryOpenVehicleMarketMenu},
	nil,
	5,
	false,
	true,
	"",
	"(isPlayer _this) and ([_this] call A3A_fnc_isMember)",
	3
]; 