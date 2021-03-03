class playerMenu 
{
	idd = 70000;
	movingenable = false;
	onLoad = "['on'] call SCRT_fnc_ui_toggleMenuBlur";
	onUnload = "isMenuOpen = false; closeDialog 0; ['off'] call SCRT_fnc_ui_toggleMenuBlur; [] spawn SCRT_fnc_ui_dispose;";
	
	class Controls 
	{
		class menuTitle: TextBase
		{
			idc = 1050;
			text = "Commander Menu";
			x = "safezoneX + (1 * pixelGridNoUIScale * pixelW)";
			y = "safezoneY + (4 * pixelGridNoUIScale * pixelH)";	
			w = "24 * pixelGridNoUIScale * pixelW";
			h = "4 * pixelGridNoUIScale * pixelH";
			sizeEx = "((pixelH * (pixelGridNoUIScale) * 2) * 2.5) * 0.5";
			shadow = 2;
		};	

		class background: TextBase 
		{
			idc = 1051;
			x = "safezoneX + (0 * pixelGridNoUIScale * pixelW)";
			y = "safezoneY + (8 * pixelGridNoUIScale * pixelH)";
			w = "24 * pixelGridNoUIScale * pixelW";
			h = "safezoneH - (18 * pixelGridNoUIScale * pixelH)";
			colorBackground[] = { 0.1, 0.1, 0.1, 0.6 };
			text = "";
		};

		class messageBoxTitle: TextBase {
			idc = 1055;	
			x = "safezoneX + (25 * pixelGridNoUIScale * pixelW)";
			y = "(safezoneY + safezoneH) - (10 * pixelGridNoUIScale * pixelH)";
			w = "safezoneW - (32 * pixelGridNoUIScale * pixelW)";	
			h = "2 * pixelGridNoUIScale * pixelH";
			text = "";
			size = "((pixelH * (pixelGridNoUIScale) * 2) * 3) * 0.5";
		};

		class messageBoxText: TextBase
		{
			idc = 1056;
			type = CT_STRUCTURED_TEXT;
			font = "PuristaLight";
			text = "";
			x = "safezoneX + (25 * pixelGridNoUIScale * pixelW)";
			y = "(safezoneY + safezoneH) - (8 * pixelGridNoUIScale * pixelH)";
			w = "safezoneW - (32 * pixelGridNoUIScale * pixelW)";	
			h = "6 * pixelGridNoUIScale * pixelH";
			size = "((pixelH * (pixelGridNoUIScale) * 2) * 1.5) * 0.5";
		};

		class mapContainer: RscMapControl
		{			
			idc = 1000;			
			x = "safezoneX + (24 * pixelGridNoUIScale * pixelW)";
			y = "safezoneY + (8 * pixelGridNoUIScale * pixelH)";
			w = "safezoneW";
			h = "safezoneH - (18 * pixelGridNoUIScale * pixelH)";
		};	

		class tabSelectorTitle: headerBase
		{
			idc = 1101;			
			style = ST_CENTER;
			text = "SUPPORT"; //--- ToDo: Localize;						
			x = "safezoneX + (0 * pixelGridNoUIScale * pixelW)";
			y = "safezoneY + (8 * pixelGridNoUIScale * pixelH)";
			w = "24 * pixelGridNoUIScale * pixelW";	
			h = "3 * pixelGridNoUIScale * pixelH";			
			sizeEx = "((pixelH * (pixelGridNoUIScale) * 2) * 1.5) * 0.5";
			colorBackground[] = {0.376, 0.125, 0.043, 1};
		};		
		
		class tabSelectorLeftButton: ButtonBase
		{			
			idc = 1150;
			text = "<";
			x = "safezoneX + (0 * pixelGridNoUIScale * pixelW)";
			y = "safezoneY + (8 * pixelGridNoUIScale * pixelH)";
			w = "2.5 * pixelGridNoUIScale * pixelW";	
			h = "3 * pixelGridNoUIScale * pixelH";
			sizeEx = "((pixelH * (pixelGridNoUIScale) * 2) * 2) * 0.5";
			action = "[70000,'LEFT'] spawn SCRT_fnc_ui_changeTab; [] spawn SCRT_fnc_ui_clearSupport;";
		};

		class tabSelectorRightButton: ButtonBase
		{			
			idc = 1151;
			text = ">";
			x = "safezoneX + (21.5 * pixelGridNoUIScale * pixelW)";
			y = "safezoneY + (8 * pixelGridNoUIScale * pixelH)";
			w = "2.5 * pixelGridNoUIScale * pixelW";	
			h = "3 * pixelGridNoUIScale * pixelH";
			sizeEx = "((pixelH * (pixelGridNoUIScale) * 2) * 2) * 0.5";	
			action = "[70000,'RIGHT'] spawn SCRT_fnc_ui_changeTab; [] spawn SCRT_fnc_ui_clearSupport;";
		};					
		
		// Game Options (Client)
		class OptionsLiteTab: RscControlsGroup 
		{
			idc = 1140;			
			x = safezoneX;
			y = "safezoneY + (12 * pixelGridNoUIScale * pixelH)";
			w = "26 * pixelGridNoUIScale * pixelW";			
			h = "safezoneH - (12 * pixelGridNoUIScale * pixelH)";

			class Controls 
			{
				class clientOptionsDescriptionTitle: TextBase
				{
					idc = 5020;
					text = "Client-Side Options";
					x = "1 * pixelGridNoUIScale * pixelW";
					y = "0 * pixelGridNoUIScale * pixelH";	
					w = "22 * pixelGridNoUIScale * pixelW";	
					h = "1.5 * pixelGridNoUIScale * pixelH";
				};

				class clientOptionsDescriptionText: TextBaseMT
				{
					idc = 5021;			
					text = "Options below are client-side only.";
					x = "1 * pixelGridNoUIScale * pixelW";
					y = "2 * pixelGridNoUIScale * pixelH";	
					w = "22 * pixelGridNoUIScale * pixelW";	
					h = "1.5 * pixelGridNoUIScale * pixelH";
					colorText[] = {1,1,1,0.7};
				};

				class musicSwitchButton: RscControlsGroupNoScrollbars 
				{
					idc = 5100;
					y = "4 * pixelGridNoUIScale * pixelH";
					class Controls 
					{
						class SwitchPic: switchButtonPic
						{			
							idc = 5101;
							text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\listen_ca.paa";
						};
						class SwitchTitle: switchButtonTitle
						{			
							idc = 5102;	
							text = "MUSIC";
						};
						class SwitchText: switchButtonSelect
						{			
							idc = 5103;
							text = "";
						};
						class SwitchButton: switchButton {
							idc = 5104;
							action = "['MAIN', 5100, true, 'MUSIC'] call SCRT_fnc_ui_switchButton";
							tooltip = "Disables/Enable situational music.";
						};
					};		
				};

				class rocketCameraSwitchButton: RscControlsGroupNoScrollbars 
				{
					idc = 5200;
					y = "7.5 * pixelGridNoUIScale * pixelH";
					class Controls 
					{
						class SwitchPic: switchButtonPic
						{			
							idc = 5201;
							text = "\A3\ui_f\data\igui\cfg\simpleTasks\types\scout_ca.paa";
						};
						class SwitchTitle: switchButtonTitle
						{			
							idc = 5202;	
							text = "ROCKET CAMERA";
						};
						class SwitchText: switchButtonSelect
						{			
							idc = 5203;
							text = "";
						};
						class SwitchButton: switchButton {
							idc = 5204;
							action = "['MAIN', 5200, true, 'CAMERA'] call SCRT_fnc_ui_switchButton";
							tooltip = "Enables/Disables camera that follows any projectile that has been launched from missile/rocket launchers. Client-side. Experimental.";
						};
					};		
				};

				class saveGameButton: ButtonBase
				{		
					idc = 5300;
					text = "PERSONAL SAVE";
					x = "1 * pixelGridNoUIScale * pixelW";
					y = "safezoneH - (26 * pixelGridNoUIScale * pixelH)";
					w = "22 * pixelGridNoUIScale * pixelW";	
					h = "3 * pixelGridNoUIScale * pixelH";
					sizeEx = "((pixelH * (pixelGridNoUIScale) * 2) * 1.25) * 0.5";	
					shadow = 2;			
					colorBackground[] = {0.376, 0.125, 0.043, 1};
					tooltip = "Use this option to save your current game. It does save the most important data in a ""Grand Theft Auto"" way. This option allows good MP save and independent saves of any version update. Vanilla saves are disabled because of lack of several features";
					action = "closeDialog 0; closeDialog 0; [] spawn A3A_fnc_persistentSave;";				
				};
			};
		};

		// INFO
		class GameInfoTab: RscControlsGroup 
		{
			idc = 2000;			
			x = -0.4 * safezoneW + safezoneX;
			y = "safezoneY + (12 * pixelGridNoUIScale * pixelH)";
			w = "26 * pixelGridNoUIScale * pixelW";			
			h = "safezoneH - (12 * pixelGridNoUIScale * pixelH)";
			
			class Controls 
			{
				class gameInfoDescriptionTitle: TextBase
				{
					idc = 2010;
					text = "Game Info";
					x = "1 * pixelGridNoUIScale * pixelW";
					y = "0 * pixelGridNoUIScale * pixelH";	
					w = "22 * pixelGridNoUIScale * pixelW";	
					h = "1.5 * pixelGridNoUIScale * pixelH";
				};

				class gameInfoDescriptionText: TextBaseMT
				{
					idc = 2011;			
					text = "";
					x = "1 * pixelGridNoUIScale * pixelW";
					y = "2 * pixelGridNoUIScale * pixelH";	
					w = "22 * pixelGridNoUIScale * pixelW";	
					h = "6 * pixelGridNoUIScale * pixelH";
					colorText[] = {1,1,1,0.7};
				};
			};
		};
	};
};