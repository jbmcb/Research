#include <Windows.h>
#include <d2d1.h>
#include <wincodec.h>
#include <dwrite.h>
#include <chrono>
#include <vector>
#include <map>
#include <limits>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <locale>
#include <codecvt>
#include <cmath>
#include <d2d1helper.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "windowscodecs.lib")
#pragma comment(lib, "dwrite.lib")



// Player Sprites
LPCWSTR playerStationaryDown = L"Sprites\\Player\\playerstationarydown.png";
LPCWSTR playerWalkingDownLeft = L"Sprites\\Player\\playerwalkingdownleft.png";
LPCWSTR playerWalkingDownRight = L"Sprites\\Player\\playerwalkingdownright.png";
LPCWSTR playerStationaryUp = L"Sprites\\Player\\playerstationaryup.png";
LPCWSTR playerWalkingUpLeft = L"Sprites\\Player\\playerwalkingupleft.png";
LPCWSTR playerWalkingUpRight = L"Sprites\\Player\\playerwalkingupright.png";
LPCWSTR playerStationaryLeft = L"Sprites\\Player\\playerstationaryleft.png";
LPCWSTR playerWalkingLeftLeft = L"Sprites\\Player\\playerwalkingleftleft.png";
LPCWSTR playerWalkingLeftRight = L"Sprites\\Player\\playerwalkingleftright.png";
LPCWSTR playerStationaryRight = L"Sprites\\Player\\playerstationaryright.png";
LPCWSTR playerWalkingRightLeft = L"Sprites\\Player\\playerwalkingrightleft.png";
LPCWSTR playerWalkingRightRight = L"Sprites\\Player\\playerwalkingrightright.png";
LPCWSTR playerHurtBox = L"Sprites\\Debug\\hurtbox.png";
LPCWSTR playerStationaryUpBasicAttackFrames[9];
LPCWSTR playerStationaryUpBasicAttack0 = L"Sprites\\Player\\playerstationaryupbasicattack0.png";
LPCWSTR playerStationaryUpBasicAttack1 = L"Sprites\\Player\\playerstationaryupbasicattack1.png";
LPCWSTR playerStationaryUpBasicAttack2 = L"Sprites\\Player\\playerstationaryupbasicattack2.png";
LPCWSTR playerStationaryUpBasicAttack3 = L"Sprites\\Player\\playerstationaryupbasicattack3.png";
LPCWSTR playerStationaryUpBasicAttack4 = L"Sprites\\Player\\playerstationaryupbasicattack4.png";
LPCWSTR playerStationaryUpBasicAttack5 = L"Sprites\\Player\\playerstationaryupbasicattack5.png";
LPCWSTR playerStationaryUpBasicAttack6 = L"Sprites\\Player\\playerstationaryupbasicattack6.png";
LPCWSTR playerStationaryUpBasicAttack7 = L"Sprites\\Player\\playerstationaryupbasicattack7.png";
LPCWSTR playerStationaryUpBasicAttack8 = L"Sprites\\Player\\playerstationaryupbasicattack8.png";
LPCWSTR playerLevelUp = L"Sprites\\Player\\playerLevelUp.png";
LPCWSTR playerBasicAttackR1 = L"Sprites\\Player\\Player_Basic_Attack_R1.png";
LPCWSTR playerBasicAttackR2 = L"Sprites\\Player\\Player_Basic_Attack_R2.png";
LPCWSTR playerBasicAttackR3 = L"Sprites\\Player\\Player_Basic_Attack_R3.png";
LPCWSTR playerBasicAttackR4 = L"Sprites\\Player\\Player_Basic_Attack_R4.png";
LPCWSTR playerBasicAttackR5 = L"Sprites\\Player\\Player_Basic_Attack_R5.png";
LPCWSTR playerBasicAttackR6 = L"Sprites\\Player\\Player_Basic_Attack_R6.png";
LPCWSTR playerBasicAttackL5 = L"Sprites\\Player\\Player_Basic_Attack_L5.png";
LPCWSTR playerBAttkFramesR[9] = { playerBasicAttackR1, playerBasicAttackR2, playerBasicAttackR3, playerBasicAttackR4, playerBasicAttackR5, playerBasicAttackR6, playerBasicAttackR5, playerBasicAttackR5, playerBasicAttackR5 };
LPCWSTR playerMAttkU = L"Sprites\\Player\\Player_Magic_Attack_U.png";
LPCWSTR playerMAttkD = L"Sprites\\Player\\Player_Magic_Attack_D.png";
LPCWSTR player_Blocking_U = L"Sprites\\Player\\Player_Blocking_U.png";
LPCWSTR player_Blocking_D = L"Sprites\\Player\\Player_Blocking_D.png";
LPCWSTR player_Blocking_L = L"Sprites\\Player\\Player_Blocking_L.png";
LPCWSTR player_Blocking_R = L"Sprites\\Player\\Player_Blocking_R.png";
LPCWSTR player_shadow = L"Sprites\\Player\\Player_Shadow.png";
LPCWSTR player_shadow_sideways = L"Sprites\\Player\\Player_Shadow_Sideways.png";

// Weapon Sprites
LPCWSTR testSwordBasicAttack[9];
LPCWSTR testSwordBasicAttackUp0 = L"Sprites\\Weapons\\testswordbasicattackup0.png";
LPCWSTR testSwordBasicAttackUp1 = L"Sprites\\Weapons\\testswordbasicattackup1.png";
LPCWSTR testSwordBasicAttackUp2 = L"Sprites\\Weapons\\testswordbasicattackup2.png";
LPCWSTR testSwordBasicAttackUp3 = L"Sprites\\Weapons\\testswordbasicattackup3.png";
LPCWSTR testSwordBasicAttackUp4 = L"Sprites\\Weapons\\testswordbasicattackup4.png";
LPCWSTR testSwordBasicAttackUp5 = L"Sprites\\Weapons\\testswordbasicattackup5.png";
LPCWSTR testSwordBasicAttackUp6 = L"Sprites\\Weapons\\testswordbasicattackup6.png";
LPCWSTR testSwordBasicAttackUp7 = L"Sprites\\Weapons\\testswordbasicattackup7.png";
LPCWSTR testSwordBasicAttackUp8 = L"Sprites\\Weapons\\testswordbasicattackup8.png";

// Debug
LPCWSTR playerHitBox = L"Sprites\\Debug\\hitbox.png";

// Enemy Sprites
LPCWSTR leafEnemyStationary = L"Sprites\\Enemies\\LeafDownStationary.png";
LPCWSTR leafEnemyDownWalkingLeft = L"Sprites\\Enemies\\LeafDownWalkingLeft.png";
LPCWSTR leafEnemyDownWalkingRight = L"Sprites\\Enemies\\LeafDownWalkingRight.png";
LPCWSTR leafEnemyDownHitstun = L"Sprites\\Enemies\\LeafDownHitstun.png";
LPCWSTR cherryEnemyStationary = L"Sprites\\Enemies\\Cherry_Stationary_D.png";
LPCWSTR cherryEnemyDownWalkingLeft = L"Sprites\\Enemies\\Cherry_Walking_D_1.png";
LPCWSTR cherryEnemyDownWalkingRight = L"Sprites\\Enemies\\Cherry_Walking_D_2.png";
LPCWSTR hornetEnemy1 = L"Sprites\\Enemies\\Hornet_Stationary_Down_1.png";
LPCWSTR hornetEnemy2 = L"Sprites\\Enemies\\Hornet_Stationary_Down_2.png";

// Environment
LPCWSTR testBackground = L"Sprites\\Environment\\testBackground.png";
LPCWSTR checkerBackground = L"Sprites\\Environment\\checkerBackground.png";
LPCWSTR BG_home_f = L"Sprites\\Environment\\Home_Front.png";
LPCWSTR BG_home_b = L"Sprites\\Environment\\Home_Back.png";
LPCWSTR BG_home_roof = L"Sprites\\Environment\\Home_Back_Roof.png";
LPCWSTR BG_home_p1 = L"Sprites\\Environment\\Home_Pathway_1.png";
LPCWSTR BG_home_p2 = L"Sprites\\Environment\\Home_Pathway_2.png";
LPCWSTR BG_home_interior_1 = L"Sprites\\Environment\\Home_Interior_1.png";
LPCWSTR Forest_1 = L"Sprites\\Environment\\Forest_1.png";
LPCWSTR Forest_2 = L"Sprites\\Environment\\Forest_2.png";
LPCWSTR Forest_3 = L"Sprites\\Environment\\Forest_3.png";
LPCWSTR Forest_4 = L"Sprites\\Environment\\Forest_4.png";
LPCWSTR Forest_5 = L"Sprites\\Environment\\Forest_5.png";
LPCWSTR Forest_6 = L"Sprites\\Environment\\Forest_6.png";
LPCWSTR Forest_7 = L"Sprites\\Environment\\Forest_7.png";
LPCWSTR Forest_8 = L"Sprites\\Environment\\Forest_8.png";
LPCWSTR Forest_9 = L"Sprites\\Environment\\Forest_9.png";
LPCWSTR Forest_10 = L"Sprites\\Environment\\Forest_10.png";
LPCWSTR Forest_11 = L"Sprites\\Environment\\Forest_11.png";
LPCWSTR Forest_12 = L"Sprites\\Environment\\Forest_12.png";
LPCWSTR Forest_13 = L"Sprites\\Environment\\Forest_13.png";
LPCWSTR Demo_End_Screen = L"Sprites\\Environment\\Demo_End_Screen.png";;

// UI
LPCWSTR hpBarFilling = L"Sprites\\UI\\HP_Bar_Filling.png";
LPCWSTR mpBarFilling = L"Sprites\\UI\\MP_Bar_Filling.png";
LPCWSTR expBarFilling = L"Sprites\\UI\\EXP_Bar_Filling.png";
LPCWSTR skillPanes = L"Sprites\\UI\\Skill_Panes.png";
LPCWSTR Level_Up_Back_Button_Unpressed = L"Sprites\\UI\\Focused Level Up Screen\\Level_Up_Back_Button_Unpressed.png";
LPCWSTR Level_Up_Back_Button_Pressed = L"Sprites\\UI\\Focused Level Up Screen\\Level_Up_Back_Button_Pressed.png";
LPCWSTR Level_Up_Confirm_Button_Unpressed = L"Sprites\\UI\\Focused Level Up Screen\\Level_Up_Confirm_Button_Unpressed.png";
LPCWSTR Level_Up_Confirm_Button_Pressed = L"Sprites\\UI\\Focused Level Up Screen\\Level_Up_Confirm_Button_Pressed.png";
LPCWSTR Level_Up_Overworld_Text_1 = L"Sprites\\UI\\Level_Up_Overworld_Text_1.png";
LPCWSTR Level_Up_Overworld_Text_2 = L"Sprites\\UI\\Level_Up_Overworld_Text_2.png";
LPCWSTR Level_Up_Overworld_Text_3 = L"Sprites\\UI\\Level_Up_Overworld_Text_3.png";
LPCWSTR Level_Up_Overworld_Text_4 = L"Sprites\\UI\\Level_Up_Overworld_Text_4.png";
LPCWSTR Level_Up_Overworld_Text_5 = L"Sprites\\UI\\Level_Up_Overworld_Text_5.png";
LPCWSTR Level_Up_Overworld_Text_6 = L"Sprites\\UI\\Level_Up_Overworld_Text_6.png";
LPCWSTR Level_Up_Overworld_Text_7 = L"Sprites\\UI\\Level_Up_Overworld_Text_7.png";
LPCWSTR Level_Up_Overworld_Text_8 = L"Sprites\\UI\\Level_Up_Overworld_Text_8.png";
LPCWSTR Level_Up_Overworld_Text_9 = L"Sprites\\UI\\Level_Up_Overworld_Text_9.png";
LPCWSTR Focused_Level_Up_Screen_Shell = L"Sprites\\UI\\Focused Level Up Screen\\Focused_Level_Up_Screen_Shell.png";
LPCWSTR Focused_Level_Up_Cursor = L"Sprites\\UI\\Focused Level Up Screen\\Focused_Level_Up_Cursor.png";
LPCWSTR Focused_Level_Up_Down_Arrow = L"Sprites\\UI\\Focused Level Up Screen\\Focused_Level_Up_Up_Down_Arrow.png";
LPCWSTR Stat_Number_0 = L"Sprites\\UI\\Fonts\\Stat_Number_0.png";
LPCWSTR Stat_Number_1 = L"Sprites\\UI\\Fonts\\Stat_Number_1.png";
LPCWSTR Stat_Number_2 = L"Sprites\\UI\\Fonts\\Stat_Number_2.png";
LPCWSTR Stat_Number_3 = L"Sprites\\UI\\Fonts\\Stat_Number_3.png";
LPCWSTR Stat_Number_4 = L"Sprites\\UI\\Fonts\\Stat_Number_4.png";
LPCWSTR Stat_Number_5 = L"Sprites\\UI\\Fonts\\Stat_Number_5.png";
LPCWSTR Stat_Number_6 = L"Sprites\\UI\\Fonts\\Stat_Number_6.png";
LPCWSTR Stat_Number_7 = L"Sprites\\UI\\Fonts\\Stat_Number_7.png";
LPCWSTR Stat_Number_8 = L"Sprites\\UI\\Fonts\\Stat_Number_8.png";
LPCWSTR Stat_Number_9 = L"Sprites\\UI\\Fonts\\Stat_Number_9.png";
LPCWSTR Yellow_Stat_Number_0 = L"Sprites\\UI\\Fonts\\Yellow_Stat_Number_0.png";
LPCWSTR Yellow_Stat_Number_1 = L"Sprites\\UI\\Fonts\\Yellow_Stat_Number_1.png";
LPCWSTR Yellow_Stat_Number_2 = L"Sprites\\UI\\Fonts\\Yellow_Stat_Number_2.png";
LPCWSTR Yellow_Stat_Number_3 = L"Sprites\\UI\\Fonts\\Yellow_Stat_Number_3.png";
LPCWSTR Yellow_Stat_Number_4 = L"Sprites\\UI\\Fonts\\Yellow_Stat_Number_4.png";
LPCWSTR Yellow_Stat_Number_5 = L"Sprites\\UI\\Fonts\\Yellow_Stat_Number_5.png";
LPCWSTR Yellow_Stat_Number_6 = L"Sprites\\UI\\Fonts\\Yellow_Stat_Number_6.png";
LPCWSTR Yellow_Stat_Number_7 = L"Sprites\\UI\\Fonts\\Yellow_Stat_Number_7.png";
LPCWSTR Yellow_Stat_Number_8 = L"Sprites\\UI\\Fonts\\Yellow_Stat_Number_8.png";
LPCWSTR Yellow_Stat_Number_9 = L"Sprites\\UI\\Fonts\\Yellow_Stat_Number_9.png";
LPCWSTR UI_Shell = L"Sprites\\UI\\UI_Shell.png";
LPCWSTR small_forwardslash = L"Sprites\\UI\\Fonts\\Small_forwardslash.png";
LPCWSTR plus = L"Sprites\\UI\\Fonts\\Plus.png";
LPCWSTR Pause_Menu = L"Sprites\\UI\\Pause Menu.png";
LPCWSTR Selection_Arrow = L"Sprites\\UI\\Selection_Arrow.png";
LPCWSTR save_Shell = L"Sprites\\UI\\Save_Shell.png";
LPCWSTR equip_Menu_Shell = L"Sprites\\UI\\Equipment_Menu_Shell.png";

//Fonts
LPCWSTR small_0 = L"Sprites\\UI\\Fonts\\Small_0.png";
LPCWSTR small_1 = L"Sprites\\UI\\Fonts\\Small_1.png";
LPCWSTR small_2 = L"Sprites\\UI\\Fonts\\Small_2.png";
LPCWSTR small_3 = L"Sprites\\UI\\Fonts\\Small_3.png";
LPCWSTR small_4 = L"Sprites\\UI\\Fonts\\Small_4.png";
LPCWSTR small_5 = L"Sprites\\UI\\Fonts\\Small_5.png";
LPCWSTR small_6 = L"Sprites\\UI\\Fonts\\Small_6.png";
LPCWSTR small_7 = L"Sprites\\UI\\Fonts\\Small_7.png";
LPCWSTR small_8 = L"Sprites\\UI\\Fonts\\Small_8.png";
LPCWSTR small_9 = L"Sprites\\UI\\Fonts\\Small_9.png";
LPCWSTR lower_a = L"Sprites\\UI\\Fonts\\lower_a.png";
LPCWSTR lower_b = L"Sprites\\UI\\Fonts\\lower_b.png";
LPCWSTR lower_c = L"Sprites\\UI\\Fonts\\lower_c.png";
LPCWSTR lower_d = L"Sprites\\UI\\Fonts\\lower_d.png";
LPCWSTR lower_e = L"Sprites\\UI\\Fonts\\lower_e.png";
LPCWSTR lower_f = L"Sprites\\UI\\Fonts\\lower_f.png";
LPCWSTR lower_g = L"Sprites\\UI\\Fonts\\lower_g.png";
LPCWSTR lower_h = L"Sprites\\UI\\Fonts\\lower_h.png";
LPCWSTR lower_i = L"Sprites\\UI\\Fonts\\lower_i.png";
LPCWSTR lower_j = L"Sprites\\UI\\Fonts\\lower_j.png";
LPCWSTR lower_k = L"Sprites\\UI\\Fonts\\lower_k.png";
LPCWSTR lower_l = L"Sprites\\UI\\Fonts\\lower_l.png";
LPCWSTR lower_m = L"Sprites\\UI\\Fonts\\lower_m.png";
LPCWSTR lower_n = L"Sprites\\UI\\Fonts\\lower_n.png";
LPCWSTR lower_o = L"Sprites\\UI\\Fonts\\lower_o.png";
LPCWSTR lower_p = L"Sprites\\UI\\Fonts\\lower_p.png";
LPCWSTR lower_q = L"Sprites\\UI\\Fonts\\lower_q.png";
LPCWSTR lower_r = L"Sprites\\UI\\Fonts\\lower_r.png";
LPCWSTR lower_s = L"Sprites\\UI\\Fonts\\lower_s.png";
LPCWSTR lower_t = L"Sprites\\UI\\Fonts\\lower_t.png";
LPCWSTR lower_u = L"Sprites\\UI\\Fonts\\lower_u.png";
LPCWSTR lower_v = L"Sprites\\UI\\Fonts\\lower_v.png";
LPCWSTR lower_w = L"Sprites\\UI\\Fonts\\lower_w.png";
LPCWSTR lower_x = L"Sprites\\UI\\Fonts\\lower_x.png";
LPCWSTR lower_y = L"Sprites\\UI\\Fonts\\lower_y.png";
LPCWSTR lower_z = L"Sprites\\UI\\Fonts\\lower_z.png";
LPCWSTR upper_a = L"Sprites\\UI\\Fonts\\Capital_A.png";
LPCWSTR upper_b = L"Sprites\\UI\\Fonts\\Capital_B.png";
LPCWSTR upper_c = L"Sprites\\UI\\Fonts\\Capital_C.png";
LPCWSTR upper_d = L"Sprites\\UI\\Fonts\\Capital_D.png";
LPCWSTR upper_e = L"Sprites\\UI\\Fonts\\Capital_E.png";
LPCWSTR upper_f = L"Sprites\\UI\\Fonts\\Capital_F.png";
LPCWSTR upper_g = L"Sprites\\UI\\Fonts\\Capital_G.png";
LPCWSTR upper_h = L"Sprites\\UI\\Fonts\\Capital_H.png";
LPCWSTR upper_i = L"Sprites\\UI\\Fonts\\Capital_I.png";
LPCWSTR upper_j = L"Sprites\\UI\\Fonts\\Capital_J.png";
LPCWSTR upper_k = L"Sprites\\UI\\Fonts\\Capital_K.png";
LPCWSTR upper_l = L"Sprites\\UI\\Fonts\\Capital_L.png";
LPCWSTR upper_m = L"Sprites\\UI\\Fonts\\Capital_M.png";
LPCWSTR upper_n = L"Sprites\\UI\\Fonts\\Capital_N.png";
LPCWSTR upper_o = L"Sprites\\UI\\Fonts\\Capital_O.png";
LPCWSTR upper_p = L"Sprites\\UI\\Fonts\\Capital_P.png";
LPCWSTR upper_q = L"Sprites\\UI\\Fonts\\Capital_Q.png";
LPCWSTR upper_r = L"Sprites\\UI\\Fonts\\Capital_R.png";
LPCWSTR upper_s = L"Sprites\\UI\\Fonts\\Capital_S.png";
LPCWSTR upper_t = L"Sprites\\UI\\Fonts\\Capital_T.png";
LPCWSTR upper_u = L"Sprites\\UI\\Fonts\\Capital_U.png";
LPCWSTR upper_v = L"Sprites\\UI\\Fonts\\Capital_V.png";
LPCWSTR upper_w = L"Sprites\\UI\\Fonts\\Capital_W.png";
LPCWSTR upper_x = L"Sprites\\UI\\Fonts\\Capital_X.png";
LPCWSTR upper_y = L"Sprites\\UI\\Fonts\\Capital_Y.png";
LPCWSTR upper_z = L"Sprites\\UI\\Fonts\\Capital_Z.png";
LPCWSTR invalid_char = L"Sprites\\UI\\Fonts\\Invalid_Char.png";
LPCWSTR right_arrow = L"Sprites\\UI\\Fonts\\Right_Arrow.png";
LPCWSTR apostrophe = L"Sprites\\UI\\Fonts\\apostrophe.png";
LPCWSTR left_parenthesis = L"Sprites\\UI\\Fonts\\left_parenthesis.png";
LPCWSTR right_parenthesis = L"Sprites\\UI\\Fonts\\right_parenthesis.png";
LPCWSTR comma = L"Sprites\\UI\\Fonts\\comma.png";
LPCWSTR period = L"Sprites\\UI\\Fonts\\period.png";
LPCWSTR semicolon = L"Sprites\\UI\\Fonts\\semicolon.png";
LPCWSTR forward_slash = L"Sprites\\UI\\Fonts\\Forward_Slash.png";
LPCWSTR dash = L"Sprites\\UI\\Fonts\\Dash.png";

// Misc
LPCWSTR man = L"Sprites\\Enemies\\1.png";

// Projectiles
LPCWSTR fireball = L"Sprites\\Effects\\Fireball.png";

// Pickups
LPCWSTR coin_s = L"Sprites\\Pickups\\Coin_S.png";

// Utilities
LPCWSTR blank_Sprite = L"Sprites\\Utilities\\Blank_Sprite.png";


LPCWSTR fontArray[255]{
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    apostrophe,
    left_parenthesis,
    right_parenthesis,
    invalid_char,
    plus,
    comma,
    dash,
    period,
    forward_slash,
    Stat_Number_0,
    Stat_Number_1,
    Stat_Number_2,
    Stat_Number_3,
    Stat_Number_4,
    Stat_Number_5,
    Stat_Number_6,
    Stat_Number_7,
    Stat_Number_8,
    Stat_Number_9,
    semicolon,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    upper_a,
    upper_b,
    upper_c,
    upper_d,
    upper_e,
    upper_f,
    upper_g,
    upper_h,
    upper_i,
    upper_j,
    upper_k,
    upper_l,
    upper_m,
    upper_n,
    upper_o,
    upper_p,
    upper_q,
    upper_r,
    upper_s,
    upper_t,
    upper_u,
    upper_v,
    upper_w,
    upper_x,
    upper_y,
    upper_z,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    lower_a,
    lower_b,
    lower_c,
    lower_d,
    lower_e,
    lower_f,
    lower_g,
    lower_h,
    lower_i,
    lower_j,
    lower_k,
    lower_l,
    lower_m,
    lower_n,
    lower_o,
    lower_p,
    lower_q,
    lower_r,
    lower_s,
    lower_t,
    lower_u,
    lower_v,
    lower_w,
    lower_x,
    lower_y,
    lower_z,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    apostrophe,
    apostrophe,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
    invalid_char,
};

// Images must be loaded into a container before images can be loaded and swapped onto the screen.
// I don't yet know why, but sprites will not appear on screen unless this is used
void StoreSpriteFileNames(std::vector<LPCWSTR>& spriteData)
{
    //---------------- Player Sprites -----------------//

    spriteData.emplace_back(playerStationaryDown);
    spriteData.emplace_back(playerWalkingDownLeft);
    spriteData.emplace_back(playerWalkingDownRight);
    spriteData.emplace_back(playerStationaryUp);
    spriteData.emplace_back(playerWalkingUpLeft);
    spriteData.emplace_back(playerWalkingUpRight);
    spriteData.emplace_back(playerStationaryLeft);
    spriteData.emplace_back(playerWalkingLeftLeft);
    spriteData.emplace_back(playerWalkingLeftRight);
    spriteData.emplace_back(playerStationaryRight);
    spriteData.emplace_back(playerWalkingRightLeft);
    spriteData.emplace_back(playerWalkingRightRight);
    spriteData.emplace_back(playerHurtBox);
    spriteData.emplace_back(playerStationaryUpBasicAttack0);
    spriteData.emplace_back(playerStationaryUpBasicAttack1);
    spriteData.emplace_back(playerStationaryUpBasicAttack2);
    spriteData.emplace_back(playerStationaryUpBasicAttack3);
    spriteData.emplace_back(playerStationaryUpBasicAttack4);
    spriteData.emplace_back(playerStationaryUpBasicAttack5);
    spriteData.emplace_back(playerStationaryUpBasicAttack6);
    spriteData.emplace_back(playerStationaryUpBasicAttack7);
    spriteData.emplace_back(playerStationaryUpBasicAttack8);
    spriteData.emplace_back(playerBasicAttackR1);
    spriteData.emplace_back(playerBasicAttackR2);
    spriteData.emplace_back(playerBasicAttackR3);
    spriteData.emplace_back(playerBasicAttackR4);
    spriteData.emplace_back(playerBasicAttackR5);
    spriteData.emplace_back(playerBasicAttackR6);
    spriteData.emplace_back(playerBasicAttackL5);
    spriteData.emplace_back(testSwordBasicAttackUp0);
    spriteData.emplace_back(testSwordBasicAttackUp1);
    spriteData.emplace_back(testSwordBasicAttackUp2);
    spriteData.emplace_back(testSwordBasicAttackUp3);
    spriteData.emplace_back(testSwordBasicAttackUp4);
    spriteData.emplace_back(testSwordBasicAttackUp5);
    spriteData.emplace_back(testSwordBasicAttackUp6);
    spriteData.emplace_back(testSwordBasicAttackUp7);
    spriteData.emplace_back(testSwordBasicAttackUp8);
    spriteData.emplace_back(playerLevelUp);
    spriteData.emplace_back(playerMAttkU);
    spriteData.emplace_back(playerMAttkD);
    spriteData.emplace_back(player_Blocking_U);
    spriteData.emplace_back(player_Blocking_D);
    spriteData.emplace_back(player_Blocking_L);
    spriteData.emplace_back(player_Blocking_R);
    spriteData.emplace_back(player_shadow);
    spriteData.emplace_back(player_shadow_sideways);


    //---------------- Enemies -----------------//

    // Leaf Enemy
    spriteData.emplace_back(leafEnemyStationary);
    spriteData.emplace_back(leafEnemyDownWalkingLeft);
    spriteData.emplace_back(leafEnemyDownWalkingRight);
    spriteData.emplace_back(leafEnemyDownHitstun);
    spriteData.emplace_back(cherryEnemyStationary);
    spriteData.emplace_back(cherryEnemyDownWalkingLeft);
    spriteData.emplace_back(cherryEnemyDownWalkingRight);
    spriteData.emplace_back(hornetEnemy1);
    spriteData.emplace_back(hornetEnemy2);



    //---------------- UI -----------------//

    spriteData.emplace_back(Pause_Menu);
    spriteData.emplace_back(Selection_Arrow);
    spriteData.emplace_back(right_arrow);
    spriteData.emplace_back(playerHitBox);
    spriteData.emplace_back(UI_Shell);
    spriteData.emplace_back(hpBarFilling);
    spriteData.emplace_back(mpBarFilling);
    spriteData.emplace_back(expBarFilling);
    spriteData.emplace_back(skillPanes);
    spriteData.emplace_back(Focused_Level_Up_Screen_Shell);
    spriteData.emplace_back(Level_Up_Back_Button_Pressed);
    spriteData.emplace_back(Level_Up_Back_Button_Unpressed);
    spriteData.emplace_back(Level_Up_Confirm_Button_Pressed);
    spriteData.emplace_back(Level_Up_Confirm_Button_Unpressed);
    spriteData.emplace_back(Level_Up_Overworld_Text_1);
    spriteData.emplace_back(Level_Up_Overworld_Text_2);
    spriteData.emplace_back(Level_Up_Overworld_Text_3);
    spriteData.emplace_back(Level_Up_Overworld_Text_4);
    spriteData.emplace_back(Level_Up_Overworld_Text_5);
    spriteData.emplace_back(Level_Up_Overworld_Text_6);
    spriteData.emplace_back(Level_Up_Overworld_Text_7);
    spriteData.emplace_back(Level_Up_Overworld_Text_8);
    spriteData.emplace_back(Level_Up_Overworld_Text_9);
    spriteData.emplace_back(save_Shell);
    spriteData.emplace_back(equip_Menu_Shell);


    //--------------- Fonts -------------------//
    spriteData.emplace_back(Stat_Number_0);
    spriteData.emplace_back(Stat_Number_1);
    spriteData.emplace_back(Stat_Number_2);
    spriteData.emplace_back(Stat_Number_3);
    spriteData.emplace_back(Stat_Number_4);
    spriteData.emplace_back(Stat_Number_5);
    spriteData.emplace_back(Stat_Number_6);
    spriteData.emplace_back(Stat_Number_7);
    spriteData.emplace_back(Stat_Number_8);
    spriteData.emplace_back(Stat_Number_9);
    spriteData.emplace_back(Yellow_Stat_Number_0);
    spriteData.emplace_back(Yellow_Stat_Number_1);
    spriteData.emplace_back(Yellow_Stat_Number_2);
    spriteData.emplace_back(Yellow_Stat_Number_3);
    spriteData.emplace_back(Yellow_Stat_Number_4);
    spriteData.emplace_back(Yellow_Stat_Number_5);
    spriteData.emplace_back(Yellow_Stat_Number_6);
    spriteData.emplace_back(Yellow_Stat_Number_7);
    spriteData.emplace_back(Yellow_Stat_Number_8);
    spriteData.emplace_back(Yellow_Stat_Number_9);
    spriteData.emplace_back(Focused_Level_Up_Down_Arrow);
    spriteData.emplace_back(small_0);
    spriteData.emplace_back(small_1);
    spriteData.emplace_back(small_2);
    spriteData.emplace_back(small_3);
    spriteData.emplace_back(small_4);
    spriteData.emplace_back(small_5);
    spriteData.emplace_back(small_6);
    spriteData.emplace_back(small_7);
    spriteData.emplace_back(small_8);
    spriteData.emplace_back(small_9);
    spriteData.emplace_back(small_forwardslash);
    spriteData.emplace_back(plus);
    spriteData.emplace_back(upper_a);
    spriteData.emplace_back(upper_b);
    spriteData.emplace_back(upper_c);
    spriteData.emplace_back(upper_d);
    spriteData.emplace_back(upper_e);
    spriteData.emplace_back(upper_f);
    spriteData.emplace_back(upper_g);
    spriteData.emplace_back(upper_h);
    spriteData.emplace_back(upper_i);
    spriteData.emplace_back(upper_j);
    spriteData.emplace_back(upper_k);
    spriteData.emplace_back(upper_l);
    spriteData.emplace_back(upper_m);
    spriteData.emplace_back(upper_n);
    spriteData.emplace_back(upper_o);
    spriteData.emplace_back(upper_p);
    spriteData.emplace_back(upper_q);
    spriteData.emplace_back(upper_r);
    spriteData.emplace_back(upper_s);
    spriteData.emplace_back(upper_t);
    spriteData.emplace_back(upper_u);
    spriteData.emplace_back(upper_v);
    spriteData.emplace_back(upper_w);
    spriteData.emplace_back(upper_x);
    spriteData.emplace_back(upper_y);
    spriteData.emplace_back(upper_z);
    spriteData.emplace_back(lower_a);
    spriteData.emplace_back(lower_b);
    spriteData.emplace_back(lower_c);
    spriteData.emplace_back(lower_d);
    spriteData.emplace_back(lower_e);
    spriteData.emplace_back(lower_f);
    spriteData.emplace_back(lower_g);
    spriteData.emplace_back(lower_h);
    spriteData.emplace_back(lower_i);
    spriteData.emplace_back(lower_j);
    spriteData.emplace_back(lower_k);
    spriteData.emplace_back(lower_l);
    spriteData.emplace_back(lower_m);
    spriteData.emplace_back(lower_n);
    spriteData.emplace_back(lower_o);
    spriteData.emplace_back(lower_p);
    spriteData.emplace_back(lower_q);
    spriteData.emplace_back(lower_r);
    spriteData.emplace_back(lower_s);
    spriteData.emplace_back(lower_t);
    spriteData.emplace_back(lower_u);
    spriteData.emplace_back(lower_v);
    spriteData.emplace_back(lower_w);
    spriteData.emplace_back(lower_x);
    spriteData.emplace_back(lower_y);
    spriteData.emplace_back(lower_z);
    spriteData.emplace_back(invalid_char);
    spriteData.emplace_back(right_arrow);
    spriteData.emplace_back(apostrophe);
    spriteData.emplace_back(left_parenthesis);
    spriteData.emplace_back(right_parenthesis);
    spriteData.emplace_back(comma);
    spriteData.emplace_back(period);
    spriteData.emplace_back(semicolon);
    spriteData.emplace_back(forward_slash);
    spriteData.emplace_back(dash);


    //---------------- Environment -----------------//

    // Background
    spriteData.emplace_back(testBackground);
    spriteData.emplace_back(checkerBackground);
    spriteData.emplace_back(BG_home_f);
    spriteData.emplace_back(BG_home_b);
    spriteData.emplace_back(BG_home_roof);
    spriteData.emplace_back(BG_home_p1);
    spriteData.emplace_back(BG_home_p2);
    spriteData.emplace_back(BG_home_interior_1);
    spriteData.emplace_back(Forest_1);
    spriteData.emplace_back(Forest_2);
    spriteData.emplace_back(Forest_3);
    spriteData.emplace_back(Forest_4);
    spriteData.emplace_back(Forest_5);
    spriteData.emplace_back(Forest_6);
    spriteData.emplace_back(Forest_7);
    spriteData.emplace_back(Forest_8);
    spriteData.emplace_back(Forest_9);
    spriteData.emplace_back(Forest_10);
    spriteData.emplace_back(Forest_11);
    spriteData.emplace_back(Forest_12);
    spriteData.emplace_back(Forest_13);
    spriteData.emplace_back(Demo_End_Screen);

    //--------------- Projectiles --------------------//
    spriteData.emplace_back(fireball);

    
    //--------------- Pickups ========================//
    spriteData.emplace_back(coin_s);

    //--------------- Utilities ----------------------//
    spriteData.emplace_back(blank_Sprite);
}

// Maps of info regarding various enemies
std::map<const std::string, int> experience;
const float pi = 3.141592;
std::mt19937 generator(std::random_device{}());

void populateEnemyExpList() {
    experience["Leafnir"] = 10;
}


// Interface: Starting point for Direct2D, used to create resources
ID2D1Factory* pD2DFactory = NULL;

// Object: Receives drawing commands
ID2D1HwndRenderTarget* renderTarget = NULL;

// Map of Direct2D Bitmaps
std::map<LPCWSTR, ID2D1Bitmap*> memSprites;

// Interface: Used for directwrite text
IDWriteFactory* pDWriteFactory = NULL;

// Interface: Used to specify font and paragraph format
IDWriteTextFormat* pTextFormat = NULL;

// System screen horizontal and vertical resolution, makes specifying res less wordy
const int sysScreenX = GetSystemMetrics(SM_CXSCREEN);
const int sysScreenY = GetSystemMetrics(SM_CYSCREEN);

// Multiplier to scale resolution with SNES resolution
double scalerX = static_cast<double>(sysScreenX) / 398.22222222222222222222;
double scalerY = static_cast<double>(sysScreenY) / 224;

double leftBorder = (sysScreenX / 2) - (128 * scalerX);
double rightBorder = (sysScreenX / 2) + (128 * scalerX);

// Indexes the last time the fps was updated
std::chrono::time_point<std::chrono::steady_clock> lastUpdate;

// framerate
double fps = 0.0;

// Solid color paintbrush
ID2D1SolidColorBrush* pBrush = NULL;

// Index files
std::vector<LPCWSTR> filePaths;

// Attempting to use steady_clock to prevent issues with time changes
std::chrono::steady_clock::time_point lastMoveTime = std::chrono::steady_clock::now();

// FPS Limiter
std::chrono::steady_clock::time_point timeSinceLastFrame = std::chrono::steady_clock::now();

// Game logic latency
std::chrono::steady_clock::time_point timeSinceLogicUpdate = std::chrono::steady_clock::now();




// Booleans for key presses
struct
{
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool space = false;
    bool lShift = false;
    bool escape = false;
    bool q = false;
    bool w = false;
    bool e = false;
    bool r = false;
    bool a = false;
    bool s = false;
    bool d = false;
    bool f = false;
    bool c = false;
    bool ctrl = false;
    std::string lastKeyPressed;
} keys;


// Used to cycle frames such as idle animations or effect shines
//void GenericFrameCycler()

D2D1_POINT_2F TransformPoint(const D2D1_MATRIX_3X2_F& m, const D2D1_POINT_2F& p)
{
    return D2D1::Point2F(
        p.x * m._11 + p.y * m._21 + m._31,
        p.x * m._12 + p.y * m._22 + m._32
    );
}

void GetDirectionalInput(double& xDirection, double& yDirection, bool keyRight, bool keyLeft, bool keyDown, bool keyUp)
{
    xDirection = (keyRight ? 1 : 0) - (keyLeft ? 1 : 0);
    yDirection = (keyDown ? 1 : 0) - (keyUp ? 1 : 0);
}

void TripErrorMissingFile(LPCWSTR file, int line);

void TripCustomMissingFileError(LPCWSTR file, LPCWSTR m, int line);

void TripCustomError(LPCWSTR m, int line);

// Essentially represents anything that can appear on screen
class Object
{
public:
    double xPosition = sysScreenX / 2;
    double yPosition = sysScreenY / 2;
    LPCWSTR frame = nullptr;
    LPCWSTR lastfilepath = nullptr;
    LPCWSTR secondlastfilepath = nullptr;
    double lastXDirection = 0;
    double lastYDirection = 0;
    std::chrono::steady_clock::time_point lastWalkTime = std::chrono::steady_clock::now();
    int framesWalked2 = 0;
    bool frameChanged = false;
    int state = 3;
    int count = 0;
    D2D1_RECT_F hurtbox;
    float angleDegrees = 180;

    double lastXDirection2 = 0;
    double lastYDirection2 = 0;

    struct {
        double left;
        double right;
        double up;
        double down;
    } hitbox;

    void WriteFileName(LPCWSTR file_Name)
    {
        frame = file_Name;
        frameChanged = true;
    }

    void DestroyObject()
    {
        frame = nullptr;
        frameChanged = true;
    }

    void UpdateHitBox() {
        ID2D1Bitmap* object = memSprites[frame];

        D2D1_SIZE_F size = object->GetSize();

        hitbox.left = xPosition;
        hitbox.right = xPosition + (size.width * scalerX);
        hitbox.up = yPosition;
        hitbox.down = yPosition + (size.height * scalerY);
    }

    bool CheckCollision(Object& object) {
        if (hitbox.left < object.hitbox.left + (object.hitbox.right - object.hitbox.left) &&
            hitbox.left + (hitbox.right - hitbox.left) > object.hitbox.left &&
            hitbox.up < object.hitbox.up + (object.hitbox.down - object.hitbox.up) &&
            hitbox.up + (hitbox.down - hitbox.up) > object.hitbox.up)
        {
            return true;
        }
        return false;
    }
};

// Objects but as enemies
class Enemy : public Object
{
public:
    int id;
    std::string name;
    int hp = 10;
    int maxHP = 10;
    bool damageTaken = false;
    bool alreadyHit = false;
    bool inHitstun = false;
    std::chrono::nanoseconds hitStunTime;
    std::chrono::steady_clock::time_point hitStunStartTime = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point timeSinceLastMovement = std::chrono::steady_clock::now();
    std::chrono::milliseconds moveInterval = std::chrono::milliseconds(5000);
    std::chrono::milliseconds walkInterval = std::chrono::milliseconds(166);
    double xDirection, yDirection;
    int xpGiven;
    LPCWSTR walkCycles[3];
    bool cycleUp = true;
    int walkIndex = 0;
    std::chrono::milliseconds idleInterval;
    std::chrono::steady_clock::time_point idlePoint;
    bool moving;

    Enemy(int id, float xPos, float yPos)
    {
        LPCWSTR file = L"", walkF1 = L"", walkF2 = L"";
        switch (id) {
        case 0:
            file = leafEnemyStationary;
            walkF1 = leafEnemyDownWalkingLeft;
            walkF2 = leafEnemyDownWalkingRight;
            xpGiven = 15;
            break;
        case 1:
            file = cherryEnemyStationary;
            walkF1 = cherryEnemyDownWalkingLeft;
            walkF2 = cherryEnemyDownWalkingRight;
            xpGiven = 23;
            break;
        case 2:
            file = hornetEnemy1;
            walkF1 = hornetEnemy1;
            walkF2 = hornetEnemy2;
            xpGiven = 33;
            walkInterval = std::chrono::milliseconds(10);
            break;
        case 3:
            break;
        case 4:
            break;
        }
        xPosition = xPos + leftBorder;
        yPosition = yPos;
        frame = file;
        lastfilepath = frame;
        secondlastfilepath = leafEnemyDownWalkingRight;
        walkCycles[0] = walkF1;
        walkCycles[1] = file;
        walkCycles[2] = walkF2;
        frameChanged = true;
        SetEnemyHurtBox();
        xDirection = (rand() % 200) - 100;
        yDirection = (rand() % 200) - 100;
        xDirection /= 100;
        yDirection /= 100;
        moveInterval = std::chrono::milliseconds((rand() % 2000) + 1500);
    }

    void SetEnemyHurtBox()
    {
        // Get the bitmap for the currently loaded file
        ID2D1Bitmap* pBitmap = memSprites[frame];
        if (pBitmap)
        {
            D2D1_SIZE_F size = pBitmap->GetSize();
            hurtbox = D2D1::RectF(xPosition, yPosition,
                (size.width * scalerX) + xPosition, (size.height * scalerY) + yPosition);
        }

    }

    void MoveEnemy(double xDirection, double yDirection)
    {
        xPosition += xDirection;
        yPosition += yDirection;

        lastXDirection2 = xDirection;
        lastYDirection2 = yDirection;
        SetEnemyHurtBox();
    }

    void DisplaceEnemy(double xDirection, double yDirection)
    {
        xPosition += xDirection;
        yPosition += yDirection;
        SetEnemyHurtBox();
    }

    void EnemyWalkAnimation()
    {
        if (std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - lastWalkTime) >= walkInterval)
        {
            if (id == 2) {
                if (frame == hornetEnemy1) frame = hornetEnemy2;
                else frame = hornetEnemy1;
            }
            if (cycleUp) walkIndex = min(2, walkIndex + 1);
            else walkIndex = max(0, walkIndex - 1);
            if (walkIndex == 0 || walkIndex == 2) cycleUp = !cycleUp;
            lastfilepath = frame;
            frame = walkCycles[walkIndex];
            lastWalkTime = std::chrono::steady_clock::now();
            frameChanged = true;
        }
    }

    void EnemyHitstunAnimation(std::chrono::nanoseconds time)
    {
        frame = leafEnemyDownHitstun;
        lastfilepath = nullptr;
        secondlastfilepath = nullptr;
        hitStunTime = time;
        hitStunStartTime = std::chrono::steady_clock::now();
    }
};

class Player : public Object
{
public:

    bool inLevelUpSequence = false;
    bool inLevelUpFanfare = false;
    std::chrono::steady_clock::time_point levelUpFanfareBegin = std::chrono::steady_clock::now();

    int level = 1;
    double exp = 0;
    double levelup = 100;

    double HP = 100;
    double maxHP = 100;
    double MP = 50;
    double maxMP = 50;
    
    int strength;
    int agility;
    int intelligence;
    int wisdom;
    int defense;
    int magicDefense;
    int trueDefense;
    int luck;
    int dexterity = 9;

    int currency = 0;

    char facingDirection = 'd';
    __int8 bAttkFrame = -1;
    unsigned __int8 atkFrames = (sizeof(playerStationaryUpBasicAttackFrames) / sizeof(playerStationaryUpBasicAttackFrames[0])) - 1;
    unsigned __int8 mId = 0;
    unsigned __int8 lvlUpStats[7];
    bool statsUpdated = false;
    int equipment[4];

    std::vector<std::chrono::nanoseconds> refreshTimes;

    int statSelection = 0;
    std::chrono::steady_clock::time_point timeSinceLastStatSelection = std::chrono::steady_clock::now();
    bool statSelected = false;
    std::chrono::steady_clock::time_point backButtonAnimationInterval = std::chrono::steady_clock::now();
    LPCWSTR lastBackButtonFile = Level_Up_Back_Button_Unpressed;
    std::chrono::steady_clock::time_point confirmButtonAnimationInterval = std::chrono::steady_clock::now();
    LPCWSTR lastConfirmButtonFile = Level_Up_Confirm_Button_Unpressed;
    std::chrono::steady_clock::time_point timeIncrementingNumberwasHeld = std::chrono::steady_clock::now();

    // Player Clocks
    std::chrono::steady_clock::time_point lastBasicAttackFrame = std::chrono::steady_clock::now();
    std::chrono::nanoseconds basicAttackFrameIncrements = std::chrono::milliseconds(16);
    std::chrono::nanoseconds basicAttackStartLag = std::chrono::microseconds(8888);
    std::chrono::nanoseconds basicAttackEndLag = std::chrono::nanoseconds(133333333);
    std::chrono::nanoseconds hitLag = std::chrono::nanoseconds(0);
    std::chrono::nanoseconds walkAnimationInterval = std::chrono::nanoseconds(166666666);
    std::chrono::steady_clock::time_point lastLevelUpOverworldTextTime;
    std::chrono::steady_clock::time_point dmgLagStarted;
    std::chrono::nanoseconds dmgLagDur = std::chrono::nanoseconds(166666666);
                                                                   


    bool isBasicAttacking = false;
    LPCWSTR weaponFileName;
    double weaponXPosition = xPosition;
    double weaponYPosition = yPosition;
    int basicAttackFrameThresholds = 1;
    D2D1_RECT_F hitbox;
    bool madeContact = false;
    bool frameAdvanced = false;
    LPCWSTR hpBarFileName;
    LPCWSTR levelUpOverworldTextFileName = nullptr;
    LPCWSTR lastLevelUpOverworldTextFileName = nullptr;
    int bobberUpper = 0;
    std::chrono::steady_clock::time_point timePointofLastBob = std::chrono::steady_clock::now();
    bool lastBobWasZero = true;
    bool mAttking = false;
    std::chrono::steady_clock::time_point mAttkBegins = std::chrono::steady_clock::now();
    std::chrono::milliseconds mAttkDur = std::chrono::milliseconds(200);
    std::chrono::steady_clock::time_point shotFireball = std::chrono::steady_clock::now();
    std::chrono::milliseconds mAttkSpeed = std::chrono::milliseconds(300);
    
    bool iFrameActive = false;
    std::chrono::seconds totaliFrames = std::chrono::seconds(1);
    std::chrono::steady_clock::time_point iFramesStart = std::chrono::steady_clock::now();
    std::chrono::milliseconds flickerInterval = std::chrono::milliseconds(250);
    std::chrono::milliseconds flickerTime = std::chrono::milliseconds(50);
    std::chrono::steady_clock::time_point lastFlicker = std::chrono::steady_clock::now();
    LPCWSTR frameBeforeiFrame;
    bool blocking = false;


    float wpnXOff[9] = {
        (10.0 / 13), (12.0 / 13), (12.0 / 13),
        (11.0 / 13), (5.0 / 13), -(6.0 / 13),
        -(15.0 / 13), -(18.0 / 13), -(15.0 / 13) };

    float wpnYOff[9] = {
        (13.0 / 21), (11.0 / 21), 0,
        -(10.0 / 21), -(13.0 / 21), -(10.0 / 21),
        -(6.0 / 21), (1.0 / 21), (13.0 / 21) };

    Player()
    {
        frame = playerStationaryDown;
        frameChanged = true;
        SetPlayerHurtBox();
    }

    void PlayerIdle()
    {
        secondlastfilepath = nullptr;
        if (lastfilepath == playerWalkingDownLeft || lastfilepath == playerStationaryDown || lastfilepath == playerWalkingDownRight)
        {
            frame = playerStationaryDown;
        }
        else if (lastfilepath == playerWalkingUpLeft || lastfilepath == playerStationaryUp || lastfilepath == playerWalkingUpRight)
        {
            frame = playerStationaryUp;
        }
        else if (lastfilepath == playerWalkingLeftLeft || lastfilepath == playerStationaryLeft || lastfilepath == playerWalkingLeftRight)
        {
            frame = playerStationaryLeft;
        }
        else if (lastfilepath == playerWalkingRightLeft || lastfilepath == playerStationaryRight || lastfilepath == playerWalkingRightRight)
        {
            frame = playerStationaryRight;
        }
        lastXDirection = 0;
        lastYDirection = 0;
        lastfilepath = frame;
        frameChanged = true;
        SetPlayerHurtBox();
    }

    // These functions are designed to condense the walking logic and make the PlayerWalkLogic function more readable
    void PlayerWalkingDownLogic(double xDirection, double yDirection)
    {
        facingDirection = 'd';
        angleDegrees = 180;
        if (lastfilepath != playerStationaryDown && lastfilepath != playerWalkingDownLeft && lastfilepath != playerWalkingDownRight)
        {
            frame = playerWalkingDownLeft;
            lastfilepath = frame;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerStationaryDown && secondlastfilepath == nullptr)
        {
            frame = playerWalkingDownLeft;
            lastfilepath = frame;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerWalkingDownLeft && secondlastfilepath == nullptr)
        {
            frame = playerStationaryDown;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerStationaryDown && secondlastfilepath == playerWalkingDownLeft)
        {
            frame = playerWalkingDownRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerWalkingDownRight && secondlastfilepath == playerStationaryDown)
        {
            frame = playerStationaryDown;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerStationaryDown && secondlastfilepath == playerWalkingDownRight)
        {
            frame = playerWalkingDownLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerWalkingDownLeft && secondlastfilepath == playerStationaryDown)
        {
            frame = playerStationaryDown;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        lastXDirection = xDirection;
        lastYDirection = yDirection;
    }
    void PlayerWalkingUpLogic(double xDirection, double yDirection)
    {
        facingDirection = 'u';
        angleDegrees = 0;
        if (lastfilepath != playerStationaryUp && lastfilepath != playerWalkingUpLeft && lastfilepath != playerWalkingUpRight)
        {
            frame = playerWalkingUpLeft;
            lastfilepath = frame;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerStationaryUp && secondlastfilepath == nullptr)
        {
            frame = playerWalkingUpLeft;
            lastfilepath = frame;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerWalkingUpLeft && secondlastfilepath == nullptr)
        {
            frame = playerStationaryUp;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerStationaryUp && secondlastfilepath == playerWalkingUpLeft)
        {
            frame = playerWalkingUpRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerWalkingUpRight && secondlastfilepath == playerStationaryUp)
        {
            frame = playerStationaryUp;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerStationaryUp && secondlastfilepath == playerWalkingUpRight)
        {
            frame = playerWalkingUpLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerWalkingUpLeft && secondlastfilepath == playerStationaryUp)
        {
            frame = playerStationaryUp;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        lastXDirection = xDirection;
        lastYDirection = yDirection;
    }
    void PlayerWalkingLeftLogic(double xDirection, double yDirection)
    {
        facingDirection = 'l';
        angleDegrees = 270;
        if (lastfilepath != playerStationaryLeft && lastfilepath != playerWalkingLeftLeft && lastfilepath != playerWalkingLeftRight)
        {
            frame = playerWalkingLeftLeft;
            lastfilepath = frame;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerStationaryLeft && secondlastfilepath == nullptr)
        {
            frame = playerWalkingLeftLeft;
            lastfilepath = frame;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerWalkingLeftLeft && secondlastfilepath == nullptr)
        {
            frame = playerStationaryLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerStationaryLeft && secondlastfilepath == playerWalkingLeftLeft)
        {
            frame = playerWalkingLeftRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerWalkingLeftRight && secondlastfilepath == playerStationaryLeft)
        {
            frame = playerStationaryLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerStationaryLeft && secondlastfilepath == playerWalkingLeftRight)
        {
            frame = playerWalkingLeftLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerWalkingLeftLeft && secondlastfilepath == playerStationaryLeft)
        {
            frame = playerStationaryLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        lastXDirection = xDirection;
        lastYDirection = yDirection;
    }
    void PlayerWalkingRightLogic(double xDirection, double yDirection)
    {
        facingDirection = 'r';
        angleDegrees = 90;
        if (lastfilepath != playerStationaryRight && lastfilepath != playerWalkingRightLeft && lastfilepath != playerWalkingRightRight)
        {
            frame = playerWalkingRightLeft;
            lastfilepath = frame;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerStationaryRight && secondlastfilepath == nullptr)
        {
            frame = playerWalkingRightLeft;
            lastfilepath = frame;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerWalkingRightLeft && secondlastfilepath == nullptr)
        {
            frame = playerStationaryRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerStationaryRight && secondlastfilepath == playerWalkingRightLeft)
        {
            frame = playerWalkingRightRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerWalkingRightRight && secondlastfilepath == playerStationaryRight)
        {
            frame = playerStationaryRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerStationaryRight && secondlastfilepath == playerWalkingRightRight)
        {
            frame = playerWalkingRightLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        else if (lastfilepath == playerWalkingRightLeft && secondlastfilepath == playerStationaryRight)
        {
            frame = playerStationaryRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = frame;
        }
        lastXDirection = xDirection;
        lastYDirection = yDirection;
    }

    void PlayerWalkLogic(double xDirection, double yDirection)
    {   // An eyeful to read
        if (std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - lastWalkTime) >= walkAnimationInterval)
            //&& ((yDirection == 0 && (((abs(xDirection) - abs(lastXDirection)) != 0)) || (xDirection == 0 && ((abs(yDirection) - abs(lastYDirection)) != 0)))
            //|| (yDirection == 0 && ((xDirection * lastXDirection) < 0) || (xDirection == 0 && (yDirection * lastYDirection) < 0)))*/)
        {
            // Checks for Diagonal movement and changes logic accordingly
            if ((yDirection > 0 && xDirection != 0) && (lastfilepath == playerStationaryDown
                || lastfilepath == playerWalkingDownLeft || lastfilepath == playerWalkingDownRight))
            {
                PlayerWalkingDownLogic(xDirection, yDirection);

            }
            else if ((yDirection < 0 && xDirection != 0) && (lastfilepath == playerStationaryUp
                || lastfilepath == playerWalkingUpLeft || lastfilepath == playerWalkingUpRight))
            {
                PlayerWalkingUpLogic(xDirection, yDirection);
            }
            else if ((xDirection < 0 && yDirection != 0) && (lastfilepath == playerStationaryLeft
                || lastfilepath == playerWalkingLeftLeft || lastfilepath == playerWalkingLeftRight))
            {
                PlayerWalkingLeftLogic(xDirection, yDirection);
            }
            else if ((xDirection > 0 && yDirection != 0) && (lastfilepath == playerStationaryRight
                || lastfilepath == playerWalkingRightLeft || lastfilepath == playerWalkingRightRight))
            {
                PlayerWalkingRightLogic(xDirection, yDirection);
            }

            // If no diagonal movement, just animate in direciton player's facing.
            else if (yDirection > 0)
            {
                PlayerWalkingDownLogic(xDirection, yDirection);
            }
            else if (yDirection < 0)
            {
                PlayerWalkingUpLogic(xDirection, yDirection);
            }
            else if (xDirection < 0)
            {
                PlayerWalkingLeftLogic(xDirection, yDirection);
            }
            else if (xDirection > 0)
            {
                PlayerWalkingRightLogic(xDirection, yDirection);
            }

            lastWalkTime = std::chrono::steady_clock::now();
            frameChanged = true;
        }
    }

    // Sets the hurtbox for the player. This is how the game knows if the player has been hit or is touching something.
    void SetPlayerHurtBox()
    {
        ID2D1Bitmap* pBitmap = memSprites[frame];
        if (pBitmap)
        {
            D2D1_SIZE_F size = pBitmap->GetSize();
            hurtbox = D2D1::RectF(xPosition, yPosition,
                (size.width * scalerX) + xPosition, (size.height * scalerY) + yPosition);
        }

    }

    // Displaces the Player
    void MovePlayer(double xDirection, double yDirection)
    {
        xPosition += xDirection;
        yPosition += yDirection;

        lastXDirection2 = xDirection;
        lastYDirection2 = yDirection;
        SetPlayerHurtBox();
    }

    void SwapWeaponFrames(LPCWSTR nextFrame, LPCWSTR lastFrame, LPCWSTR weaponFrame) {
        weaponFileName = weaponFrame;
    }

    void SwapPlayerFramesForBAttk(char facingDirection) {
        secondlastfilepath = frame;
        switch (facingDirection) {
        case 'u':
            frame = playerStationaryUpBasicAttackFrames[bAttkFrame];
            break;
        case 'r':
            frame = playerBAttkFramesR[bAttkFrame];
            /*case 'l'
            case 'd':*/

        }
        lastfilepath = frame;
        frameChanged = true;
        return;
    }

    void BasicAttack(std::vector<Enemy>& enemies)
    {   
        if (std::chrono::steady_clock::now() - lastBasicAttackFrame >= basicAttackFrameIncrements) {
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            if (bAttkFrame < atkFrames)
            {
                lastBasicAttackFrame = std::chrono::steady_clock::now();
                if (bAttkFrame == -1) {
                    bAttkFrame = 0;
                }
                else if (bAttkFrame == atkFrames) {
                    bAttkFrame = -1;
                }
                else {
                    bAttkFrame++;
                }
                SwapPlayerFramesForBAttk(facingDirection);
                weaponFileName = testSwordBasicAttack[bAttkFrame];
                ID2D1Bitmap* pBitmap = memSprites[frame];
                if (pBitmap)
                {
                    D2D1_SIZE_F size = pBitmap->GetSize();
                    float yOffset(0);
                    if (angleDegrees == 180.0) yOffset = -4;
                    weaponXPosition = xPosition + ((size.width * wpnXOff[bAttkFrame]) * scalerX);
                    weaponYPosition = yPosition + ((yOffset + (size.height * wpnYOff[bAttkFrame])) * scalerY);
                }

                SetHitBox();
                SetPlayerHurtBox();
            }
            else if (bAttkFrame == atkFrames/* && keys.space == false*/)
            {
                bAttkFrame = -1;
                switch (facingDirection) {
                case ('u'):
                    frame = playerStationaryUp;
                    break;
                case ('d'):
                    frame = playerStationaryDown;
                    break;
                case ('l'):
                    frame = playerStationaryLeft;
                    break;
                case ('r'):
                    frame = playerStationaryRight;
                    break;
                }
                lastfilepath = frame;
                secondlastfilepath = nullptr;
                frameChanged = true;
                weaponFileName = nullptr;
                RemoveHitBox();
                SetPlayerHurtBox();
                for (int i = 0; i < enemies.size(); i++)
                {
                    enemies.at(i).alreadyHit = false;
                }
            }
        }

        if (bAttkFrame != -1)
        {
            for (int i = 0; i < enemies.size(); i++)
            {
                if (enemies.at(i).alreadyHit == false)
                {
                    if (hitbox.right >= enemies.at(i).hurtbox.left && hitbox.left <= enemies.at(i).hurtbox.right
                        && hitbox.top <= enemies.at(i).hurtbox.bottom && hitbox.bottom >= enemies.at(i).hurtbox.top)
                    {
                        dmgLagStarted = std::chrono::steady_clock::now();
                        /*enemies.at(i).damageTaken = true;*/
                        enemies.at(i).alreadyHit = true;
                        enemies.at(i).inHitstun = true;
                        enemies.at(i).hp -= strength;
                        /*double nanoseconds = (static_cast<double>(attack) / static_cast<double>(enemies.at(i).maxHP)) * 333333333;
                        hitLag = std::chrono::nanoseconds((static_cast<int>(nanoseconds)));*/

                        if (enemies.at(i).hp <= 0)
                        {
                            exp += enemies.at(i).xpGiven;
                            enemies.erase(enemies.begin() + i);
                        }
                        else
                        {
                            double nanoseconds = (static_cast<double>(strength) / static_cast<double>(enemies.at(i).maxHP)) * 333333333;
                            std::chrono::nanoseconds time = std::chrono::nanoseconds((static_cast<int>(nanoseconds)));
                            enemies.at(i).EnemyHitstunAnimation(time);
                        }
                    }
                    /*else
                    {
                        enemies.at(i).damageTaken = false;
                    }*/
                }
            }
        }

    }

    void SetHitBox()
    {
        ID2D1Bitmap* playerFrame = memSprites[frame];
        D2D1_SIZE_F playerSize = playerFrame->GetSize();
        D2D1_POINT_2F midpoint = D2D1::Point2F(
            xPosition + ((playerSize.width * scalerX) / 2),
            yPosition + ((playerSize.height * scalerY) / 2)
        );

        ID2D1Bitmap* pBitmap = memSprites[weaponFileName];
        if (!pBitmap)
            return;

        D2D1_SIZE_F size = pBitmap->GetSize();

        float width = size.width * scalerX;
        float height = size.height * scalerY;

        D2D1_RECT_F baseRect = D2D1::RectF(
            weaponXPosition,
            weaponYPosition,
            weaponXPosition + width,
            weaponYPosition + height
        );

        D2D1_MATRIX_3X2_F rotation =
            D2D1::Matrix3x2F::Rotation(angleDegrees, midpoint);

        D2D1_POINT_2F p1 = TransformPoint(rotation, D2D1::Point2F(baseRect.left, baseRect.top));
        D2D1_POINT_2F p2 = TransformPoint(rotation, D2D1::Point2F(baseRect.right, baseRect.top));
        D2D1_POINT_2F p3 = TransformPoint(rotation, D2D1::Point2F(baseRect.right, baseRect.bottom));
        D2D1_POINT_2F p4 = TransformPoint(rotation, D2D1::Point2F(baseRect.left, baseRect.bottom));

        float minX = min(min(p1.x, p2.x), min(p3.x, p4.x));
        float maxX = max(max(p1.x, p2.x), max(p3.x, p4.x));
        float minY = min(min(p1.y, p2.y), min(p3.y, p4.y));
        float maxY = max(max(p1.y, p2.y), max(p3.y, p4.y));

        hitbox = D2D1::RectF(minX, minY, maxX, maxY);
    }

    void RemoveHitBox()
    {
        hitbox.right = hitbox.left = hitbox.top = hitbox.bottom = -1;
    }

    void PlayerLevelUpSequence() {
        inLevelUpSequence = true;
        inLevelUpFanfare = true;
        frame = playerLevelUp;
        weaponFileName = nullptr;
        yPosition -= 15 * scalerY;
        RemoveHitBox();
        levelUpFanfareBegin = std::chrono::steady_clock::now();
    }

    void SwapMAttkFrames() {
        if (std::chrono::steady_clock::now() - mAttkBegins >= mAttkDur) {
            mAttking = false;
            switch (facingDirection) {
            case 'u':
                frame = playerStationaryUp;
                break;
            case 'd':
                frame = playerStationaryDown;
                break;
            case 'l':
                frame = playerStationaryLeft;
                break;
            case 'r':
                frame = playerStationaryRight;
                break;
            }
        }
        else {
            switch (facingDirection) {
            case 'u':
                frame = playerMAttkU;
                break;
            case 'd':
                frame = playerMAttkD;
                break;
            case 'l':
                frame = playerBasicAttackL5;
                break;
            case 'r':
                frame = playerBasicAttackR5;
                break;
            }
        }
    }

};

class Door : public Object {
public:
    float destX, destY;
    bool transferX = false, transferY = false;
    unsigned __int8 destID;
    Door(unsigned __int8 l, unsigned __int8 r, unsigned __int8 u, unsigned __int8 d, float toX, float toY, unsigned __int8 toID) {
        hitbox.left = (l * scalerX) + leftBorder;
        hitbox.right = (r * scalerX) + leftBorder;
        hitbox.up = u * scalerY;
        hitbox.down = d * scalerY;
        if (toX == -1) transferX = true;
        else destX = (toX * scalerX) + leftBorder;
        if (toY == -1) transferY = true;
        else destY = toY * scalerY;
        destID = toID;
    }
};

class Environment {
public:
    unsigned __int8 id;
    LPCWSTR frame;
    std::vector<Door> doors;
    std::vector<Object> props;
    class EnemyData {
    public:
        int enemyID;
        float sPosX, sPosY;
        bool deathStatus, spawned;
        EnemyData(int id, float posX, float posY, bool d) {
            enemyID = id;
            sPosX = posX;
            sPosY = posY;
            deathStatus = d;
            spawned = false;
        }
    };
    std::vector<EnemyData> enemyData;

    Environment(LPCWSTR file, unsigned __int8 ident) {
        frame = file;
        id = ident;
    }

    void AddDoor(unsigned __int8 l, unsigned __int8 r, unsigned __int8 u, unsigned __int8 d, float toX, float toY, unsigned __int8 toID) {
        doors.emplace_back(l, r, u, d, toX, toY, toID);
    }

    void AddProp(LPCWSTR file, float x, float y) {
        props.emplace_back();
        props.back().xPosition = leftBorder + (x * scalerX);
        props.back().yPosition = (y * scalerY);
        props.back().frame = file;
    }
};

class Projectile : public Object {
public:
    float xVel, yVel, power;
    Projectile(LPCWSTR f, float x, float y, float xV, float yV, float p, float a) {
        xPosition = x;
        yPosition = y;
        xVel = xV;
        yVel = yV;
        frame = f;
        power = p;
        angleDegrees = a;
    }
};

class Equipment {
public:
    int statModifiers[7]; // 1str, 2agi, 3intl, 4wis, 5def, 6mdef, 7luck
    std::string name;

    Equipment() {}

    Equipment(std::string n, int str, int agi, int intl, int wis, int def, int mdef, int lck) {
        name = n;
        statModifiers[0] = str;
        statModifiers[1] = agi;
        statModifiers[2] = intl;
        statModifiers[3] = wis;
        statModifiers[4] = def;
        statModifiers[5] = mdef;
        statModifiers[6] = lck;
    }
};

/*class Enemy : public Object
{
    int leafEnemyWalkFrames = 0;
    void MoveObject(double xDir, double yDir)
    {
        xPosition += xDir;
        yPosition += yDir;
    }
};*/

void ApplyPlayerDirectionalInput(Player& player, std::chrono::steady_clock::time_point currentFrameTime, double xDir, double yDir)
{
        player.MovePlayer(xDir, yDir);
        if ((player.hurtbox.left >= leftBorder && player.hurtbox.top >= 0
            && player.hurtbox.right <= rightBorder && player.hurtbox.bottom <= sysScreenY) 
            || ((player.hurtbox.left <= leftBorder || player.hurtbox.right >= rightBorder) && yDir != 0)
            || ((player.hurtbox.top <= 0 || player.hurtbox.bottom >= sysScreenY) && xDir != 0))
        {
            player.PlayerWalkLogic(xDir, yDir);
        }
        else
        {
            player.PlayerIdle();
        }

        // If the player was moved out of bounds, snaps them back in bounds
        if (player.hurtbox.left <= leftBorder)
        {
            double movement = leftBorder - player.hurtbox.left;
            player.MovePlayer(0.00001 + leftBorder - player.hurtbox.left, 0);
        }
        if (player.hurtbox.top <= 0)
        {
            player.MovePlayer(0, 0 - player.hurtbox.top + 0.00001);
        }
        if (player.hurtbox.right >= rightBorder)
        {
            player.MovePlayer(rightBorder - player.hurtbox.right - 0.00001, 0);
        }
        if (player.hurtbox.bottom >= sysScreenY)
        {
            player.MovePlayer(0, sysScreenY - player.hurtbox.bottom - 0.00001);
        }
}

void ApplyEnemyDirectionalInput(Enemy& enemy, double xDir, double yDir)
{
    enemy.SetEnemyHurtBox();
    if (xDir != 0 || yDir != 0)
    {
        enemy.MoveEnemy(xDir, yDir);

        // If the enemy was moved out of bounds, snaps them back in bounds
        if (enemy.hurtbox.left <= leftBorder)
        {
            enemy.DisplaceEnemy(leftBorder - enemy.hurtbox.left, 0);
            enemy.lastXDirection2 *= -1;
        }
        if (enemy.hurtbox.top <= 0)
        {
            enemy.DisplaceEnemy(0, 0 - enemy.hurtbox.top);
            enemy.lastYDirection2 *= -1;
        }
        if (enemy.hurtbox.right >= rightBorder)
        {
            enemy.DisplaceEnemy(rightBorder - enemy.hurtbox.right, 0);
            enemy.lastXDirection2 *= -1;
        }
        if (enemy.hurtbox.bottom >= sysScreenY)
        {
            enemy.DisplaceEnemy(0, sysScreenY - enemy.hurtbox.bottom);
            enemy.lastYDirection2 *= -1;
        }
    }

    if (enemy.hurtbox.left == 0 && enemy.hurtbox.top == 0
        && enemy.hurtbox.right == 0 && enemy.hurtbox.bottom == 0)
    {
        enemy.framesWalked2 = 0;
    }
    else
    {
        enemy.framesWalked2++;
    }

    enemy.EnemyWalkAnimation();
}

void LoadMemory(HWND hWnd, std::vector<LPCWSTR> spriteData)
{
    HRESULT hr = S_OK;

    if (!renderTarget)
    {
        RECT rc;
        GetClientRect(hWnd, &rc);

        D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

        hr = pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hWnd, size), &renderTarget);
    }

    if (FAILED(hr))
    {
        return;
    }

    IWICImagingFactory* pWICFactory = NULL;
    hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, reinterpret_cast<void**>(&pWICFactory));

    if (FAILED(hr))
    {
        return;
    }

    int j = 0;
    // Iterating over each file in the sprite container
    for (int i = 0; i < spriteData.size(); i++)
    {
        IWICBitmapDecoder* pDecoder = NULL;
        hr = pWICFactory->CreateDecoderFromFilename(spriteData.at(i),
            NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder);

        if (FAILED(hr))
        {
            pWICFactory->Release();
            TripCustomMissingFileError(spriteData[i], L"Failed PNG->BMP Conversion", __LINE__);
        }

        IWICBitmapFrameDecode* pSource = NULL;
        hr = pDecoder->GetFrame(0, &pSource);

        if (FAILED(hr))
        {
            pDecoder->Release();
            pWICFactory->Release();
            return;
        }

        IWICFormatConverter* pConverter = NULL;
        hr = pWICFactory->CreateFormatConverter(&pConverter);

        if (FAILED(hr))
        {
            pSource->Release();
            pDecoder->Release();
            pWICFactory->Release();
            return;
        }

        hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.0, WICBitmapPaletteTypeMedianCut);

        if (FAILED(hr))
        {
            pConverter->Release();
            pSource->Release();
            pDecoder->Release();
            pWICFactory->Release();
            return;
        }

        ID2D1Bitmap* pBitmap = NULL;
        hr = renderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, &pBitmap);

        if (SUCCEEDED(hr))
        {
            j++;
            memSprites[spriteData.at(i)] = pBitmap;
        }

        pConverter->Release();
        pSource->Release();
        pDecoder->Release();
    }

    pWICFactory->Release();

    hr = DWriteCreateFactory(
        DWRITE_FACTORY_TYPE_SHARED,
        __uuidof(IDWriteFactory),
        reinterpret_cast<IUnknown**>(&pDWriteFactory)
    );
    if (SUCCEEDED(hr)) {
        hr = pDWriteFactory->CreateTextFormat(
            L"Arial",
            NULL,
            DWRITE_FONT_WEIGHT_NORMAL,
            DWRITE_FONT_STYLE_NORMAL,
            DWRITE_FONT_STRETCH_NORMAL,
            20.0f,
            L"en-us",
            &pTextFormat
        );
    }

    if (SUCCEEDED(hr)) {
        hr = renderTarget->CreateSolidColorBrush(
            D2D1::ColorF(D2D1::ColorF::White),
            &pBrush
        );
    }
}

void ReleaseMemory()
{
    if (pBrush)
    {
        pBrush->Release();
        pBrush = NULL;
    }

    if (renderTarget)
    {
        renderTarget->Release();
        renderTarget = NULL;
    }
    for (auto& pair : memSprites)
    {
        ID2D1Bitmap* pBitmap = pair.second;
        if (pBitmap)
        {
            pBitmap->Release();
        }
    }
    memSprites.clear();
    if (pTextFormat)
    {
        pTextFormat->Release();
        pTextFormat = NULL;
    }
    if (pDWriteFactory)
    {
        pDWriteFactory->Release();
        pDWriteFactory = NULL;
    }
}

// Stops the game, clears resoursces, pops up error that tells user of missing file & code line, closes at ok
void TripErrorMissingFile(LPCWSTR file, int line) {
    if (pD2DFactory) pD2DFactory->Release();
    ReleaseMemory();
    MessageBox(
        NULL, 
        (std::wstring(L"Sprite Missing: ") + file).c_str(),
        L"Error",
        MB_ICONERROR | MB_OK | MB_TOPMOST | MB_SETFOREGROUND | MB_SERVICE_NOTIFICATION
    );
    exit(EXIT_FAILURE);
    return;
}

// Same as before but with extra text for added context
void TripCustomMissingFileError(LPCWSTR file, LPCWSTR m, int line) {
    if (pD2DFactory) pD2DFactory->Release();
    ReleaseMemory();
    std::wstring message = std::wstring(L"Sprite Missing: ") + file + std::wstring(L"\n");
    message += std::wstring(L"Source code line: ") + std::to_wstring(line) + std::wstring(L"\n") + std::wstring(m);
    m = message.c_str();

    MessageBox(
        NULL, 
        m,
        L"Error",
        MB_ICONERROR | MB_OK | MB_TOPMOST | MB_SETFOREGROUND | MB_SERVICE_NOTIFICATION
    );
    exit(EXIT_FAILURE); 
    return;
}

// Sends custom window popup message, closes at ok
void TripCustomError(LPCWSTR m, int line) {
    if (pD2DFactory) pD2DFactory->Release();
    ReleaseMemory();

    MessageBox(
        NULL,
        m,
        L"Error",
        MB_ICONERROR | MB_OK | MB_TOPMOST | MB_SETFOREGROUND | MB_SERVICE_NOTIFICATION
    );
    exit(EXIT_FAILURE);
    return;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

std::vector<LPCWSTR> spriteData;
Player player;
std::vector<Enemy> enemies;
int startingStats[9];
std::chrono::steady_clock::time_point currentFrameTime = std::chrono::steady_clock::now(); // Keeps tracks of screen updates
std::chrono::steady_clock::time_point debugTimer = std::chrono::steady_clock::now();
std::vector<Object> walls;
std::vector<Environment> environments;
unsigned __int8 currentEnvID(5);
int gameState(0);
std::vector<Projectile> playerProjectiles;
Equipment equipment[4];
// Game States:
// 0: In overworld game
// 1 and so on: in other menus



//--------------------------------
// Render Consolidatory Functions
//--------------------------------

void RenderStatsRight(ID2D1Bitmap* stat1, ID2D1Bitmap* stat2, ID2D1Bitmap* stat3, int xOffset, int yOffset) {
    int xOffset1, xOffset2, xOffset3;

    if (stat1 && stat2 && stat3)
    {
        D2D1_SIZE_F size1 = stat1->GetSize();
        D2D1_SIZE_F size2 = stat2->GetSize();
        D2D1_SIZE_F size3 = stat3->GetSize();
        xOffset1 = xOffset - size1.width - size2.width - size3.width;
        xOffset2 = xOffset + 1 - size2.width - size3.width;
        xOffset3 = xOffset + 2 - size3.width;
    }
    else if (stat1 && stat2)
    {
        D2D1_SIZE_F size1 = stat1->GetSize();
        D2D1_SIZE_F size2 = stat2->GetSize();
        xOffset1 = xOffset + 1 - size1.width - size2.width;
        xOffset2 = xOffset + 2 - size2.width;
    }
    else if (stat1) // if statement not necessary, but could prevent errors if stat were to somehow be emptied
    {
        D2D1_SIZE_F size1 = stat1->GetSize();
        xOffset1 = xOffset + 2 - size1.width;
    }

    if (stat1)
    {
        D2D1_SIZE_F size1 = stat1->GetSize();
        D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (xOffset1 * scalerX), yOffset * scalerY,
            (leftBorder + ((xOffset1 + size1.width) * scalerX)), ((size1.height + yOffset) * scalerY));
        renderTarget->DrawBitmap(stat1, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

        if (stat2)
        {
            D2D1_SIZE_F size2 = stat2->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (xOffset2 * scalerX), yOffset * scalerY,
                (leftBorder + ((xOffset2 + size2.width) * scalerX)), ((size2.height + yOffset) * scalerY));
            renderTarget->DrawBitmap(stat2, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

            if (stat3)
            {
                D2D1_SIZE_F size3 = stat3->GetSize();
                D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (xOffset3 * scalerX), yOffset * scalerY,
                    (leftBorder + ((xOffset3 + size3.width) * scalerX)), ((size3.height + yOffset) * scalerY));
                renderTarget->DrawBitmap(stat3, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
            }
        }
    }
}

void TranslateStatstoBitmap(int stat, ID2D1Bitmap*& bitmap1, ID2D1Bitmap*& bitmap2, ID2D1Bitmap*& bitmap3) {
    std::string statString = std::to_string(stat);
    switch (statString[0])
    {
    case '0':
        bitmap1 = memSprites[Stat_Number_0];
        break;
    case '1':
        bitmap1 = memSprites[Stat_Number_1];
        break;
    case '2':
        bitmap1 = memSprites[Stat_Number_2];
        break;
    case '3':
        bitmap1 = memSprites[Stat_Number_3];
        break;
    case '4':
        bitmap1 = memSprites[Stat_Number_4];
        break;
    case '5':
        bitmap1 = memSprites[Stat_Number_5];
        break;
    case '6':
        bitmap1 = memSprites[Stat_Number_6];
        break;
    case '7':
        bitmap1 = memSprites[Stat_Number_7];
        break;
    case '8':
        bitmap1 = memSprites[Stat_Number_8];
        break;
    case '9':
        bitmap1 = memSprites[Stat_Number_9];
        break;
    }

    if (stat >= 10) {
        switch (statString[1])
        {
        case '0':
            bitmap2 = memSprites[Stat_Number_0];
            break;
        case '1':
            bitmap2 = memSprites[Stat_Number_1];
            break;
        case '2':
            bitmap2 = memSprites[Stat_Number_2];
            break;
        case '3':
            bitmap2 = memSprites[Stat_Number_3];
            break;
        case '4':
            bitmap2 = memSprites[Stat_Number_4];
            break;
        case '5':
            bitmap2 = memSprites[Stat_Number_5];
            break;
        case '6':
            bitmap2 = memSprites[Stat_Number_6];
            break;
        case '7':
            bitmap2 = memSprites[Stat_Number_7];
            break;
        case '8':
            bitmap2 = memSprites[Stat_Number_8];
            break;
        case '9':
            bitmap2 = memSprites[Stat_Number_9];
            break;
        }
    }
    else {
        bitmap2 = nullptr;
    }

    if (stat >= 100) {
        switch (statString[2])
        {
        case '0':
            bitmap3 = memSprites[Stat_Number_0];
            break;
        case '1':
            bitmap3 = memSprites[Stat_Number_1];
            break;
        case '2':
            bitmap3 = memSprites[Stat_Number_2];
            break;
        case '3':
            bitmap3 = memSprites[Stat_Number_3];
            break;
        case '4':
            bitmap3 = memSprites[Stat_Number_4];
            break;
        case '5':
            bitmap3 = memSprites[Stat_Number_5];
            break;
        case '6':
            bitmap3 = memSprites[Stat_Number_6];
            break;
        case '7':
            bitmap3 = memSprites[Stat_Number_7];
            break;
        case '8':
            bitmap3 = memSprites[Stat_Number_8];
            break;
        case '9':
            bitmap3 = memSprites[Stat_Number_9];
            break;
        }
    }
    else {
        bitmap3 = nullptr;
    }
}

void RenderText(std::string text, unsigned __int8 x, unsigned __int8 y) {
    __int8 spacerX(0), spacerY(0);
    if (text == ":right_arrow") {
        ID2D1Bitmap* symbol = memSprites[right_arrow];
        D2D1_SIZE_F size = symbol->GetSize();
        D2D1_RECT_F destRect = D2D1::RectF(
            (x * scalerX) + leftBorder,
            y * scalerY,
            ((x + size.width) * scalerX) + leftBorder,
            (y + size.height + spacerY) * scalerY);
        renderTarget->DrawBitmap(symbol, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
    }
    else for (char c : text) {
        unsigned __int8 i = unsigned __int8(c);
        if (c == ' ') {
            spacerX += 3;
            continue;
        }
        ID2D1Bitmap* symbol = memSprites[fontArray[i]];
        D2D1_SIZE_F size = symbol->GetSize();

        if (c == 'p' || c == 'g' || c == 'q' || c == 'j' || c == 'y') {
            spacerY = 3;
        }
        else {
            spacerY = 9 - size.height;
        }
        D2D1_RECT_F destRect = D2D1::RectF(
            ((x + spacerX) * scalerX) + leftBorder, 
            (y + spacerY) * scalerY,
            ((x + size.width + spacerX) * scalerX) + leftBorder, 
            (y + size.height + spacerY) * scalerY);
        renderTarget->DrawBitmap(symbol, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

        spacerX += size.width;
    }
    return;
}

float RenderTextR(std::string text, unsigned __int8 x, unsigned __int8 y) {
    __int8 spacerX(0), spacerY(0);
    for (char c : text) {
        unsigned __int8 i = unsigned __int8(c);
        if (c == ' ') {
            spacerX += 2;
            continue;
        }
        ID2D1Bitmap* symbol = memSprites[fontArray[i]];
        D2D1_SIZE_F size = symbol->GetSize();
        spacerX += (size.width);
    }

    float xPos = x - spacerX;
    for (char c : text) {
        unsigned __int8 i = unsigned __int8(c);
        if (c == ' ') {
            xPos += 2;
            continue;
        }
        ID2D1Bitmap* symbol = memSprites[fontArray[i]];
        D2D1_SIZE_F size = symbol->GetSize();

        if (c == 'p' || c == 'g' || c == 'q' || c == 'y') {
            spacerY = 3;
        }
        else if (c == 'j') {
            spacerY = 1;
        }
        else {
            spacerY = 9 - size.height;
        }
        D2D1_RECT_F destRect = D2D1::RectF(
            ((xPos)*scalerX) + leftBorder,
            (y + spacerY) * scalerY,
            ((size.width + xPos) * scalerX) + leftBorder,
            (y + size.height + spacerY) * scalerY);
        renderTarget->DrawBitmap(symbol, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

        xPos += (size.width);
    }
    return spacerX;
}

void RenderObjLeft(LPCWSTR file, float x, float y) {
    ID2D1Bitmap* bmp = memSprites[file];
    if (!bmp) TripErrorMissingFile(file, __LINE__);
    D2D1_SIZE_F size = bmp->GetSize();
    D2D1_RECT_F dispPos = D2D1::RectF(x, y, x + (size.width * scalerX), y + (size.height * scalerY));
    renderTarget->DrawBitmap(bmp, dispPos, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}

void RenderObjMid(LPCWSTR file, float x, float y) {
    ID2D1Bitmap* bmp = memSprites[file];
    if (!bmp) TripErrorMissingFile(file, __LINE__);
    D2D1_SIZE_F size = bmp->GetSize();
    D2D1_RECT_F dispPos = D2D1::RectF(x - ((size.width/2) * scalerX), y - ((size.height/2) * scalerY), x + ((size.width/2) * scalerX), y + ((size.height/2) * scalerY));
    renderTarget->DrawBitmap(bmp, dispPos, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}

std::chrono::steady_clock::time_point lastMenuInput = std::chrono::steady_clock::now();
std::chrono::milliseconds menInputBuffer = std::chrono::milliseconds(100);

class Stopwatch {
public:
    std::chrono::steady_clock::time_point startTime;
    unsigned int duration;

    Stopwatch() {
        duration = 0;
    }

    void Start() {
        startTime = std::chrono::steady_clock::now();
    }

    void Stop() {
        duration = duration + int(std::chrono::duration<double>(std::chrono::steady_clock::now() - startTime).count());
    }
};

Stopwatch stopwatch;

class MenuElement : public Object {
public:
    MenuElement(LPCWSTR path, int x, int y) {
        frame = path;
        xPosition = x;
        yPosition = y;
    }
};

class Menu {
public:
    __int8 selection = 0;
    __int8 selecSize = 2;
    unsigned __int8 state = 0;
    std::vector<MenuElement> menuElements;
    bool holdU = false;
    bool holdD = false;
    bool justArriving = false;

    void ChangeSelection(bool up, bool down) {
        if (up) {
            holdU = true;
            lastMenuInput = std::chrono::steady_clock::now();
            selection = max(0, selection - 1);
        }
        else {
            holdU = false;
        }
        if (down) {
            holdD = true;
            lastMenuInput = std::chrono::steady_clock::now();
            selection = min(selecSize - 1, selection + 1);
        }
        else {
            holdD = false;
        }
    }
};

class SaveMenu : public Menu {
public:
    int selection = 0;
    int selecSize = 3;
    std::string name[3];
    int dispAttr[3][2];
    int fileSelection = 0;

    SaveMenu() {
        menuElements.emplace_back(save_Shell, 83, 10);
        menuElements.emplace_back(Selection_Arrow, leftBorder + (92 * scalerX), (60 + (selection * 33)) * scalerY);
        std::ifstream inFile((L"Save\\Save.txt"));
        std::string line;
        int i = 0;
        int state = 0;
        while (std::getline(inFile, line)) {
            if (line == "-1") {
                for (int j = 0; j < 5; j++) std::getline(inFile, line);
                name[i] = "-";
                dispAttr[i][0] = -1;
                dispAttr[i][1] = -1;
                i++;
            }
            else {
                name[i] = line;
                std::getline(inFile, line);
                dispAttr[i][0] = stoi(line);
                std::getline(inFile, line);
                dispAttr[i][1] = stoi(line);
                std::getline(inFile, line);
                std::getline(inFile, line);
                std::getline(inFile, line);
                i++;
            }
        }
    }

    bool LoadGame() {
        std::ifstream inFile((L"Save\\Save.txt"));
        if (inFile.is_open()) {

            std::string line;
            __int8 index = (fileSelection * 6);
            for (int i = 0; i < index; i++) {
                std::getline(inFile, line);
            }
            std::getline(inFile, line); // file name
            if (line == "-1") return false;
            std::getline(inFile, line); // time
            stopwatch.duration = stoi(line);
            stopwatch.Start();
            std::getline(inFile, line); // curr
            player.currency = stoi(line);
            std::getline(inFile, line); // xPos
            player.xPosition = stoi(line);
            std::getline(inFile, line); // yPos
            player.yPosition = stoi(line);
            std::getline(inFile, line); // env ID
            currentEnvID = stoi(line);
            selection = 0;
            state = 0;
            gameState = 0;
            inFile.close();
            return true;
        }
    }

    void SaveGame() {
        stopwatch.Stop();
        stopwatch.Start();
        std::ifstream in("Save\\Save.txt");
        std::ofstream out("Save\\Temp.txt");
        std::string line;
        int lineNum = (fileSelection * 6);

        // go line by line and copy all but current file info
        for (int i = 0; i <= 18; i++) {
            if (i == lineNum) {
                std::getline(in, line);
                out << line << "\n";
                out << std::to_string(stopwatch.duration) << "\n";
                out << std::to_string(player.currency) << "\n";
                out << player.xPosition << "\n";
                out << player.yPosition << "\n";
                out << std::to_string(currentEnvID) << "\n";
                for (int j = 0; j < 5; j++) {
                    std::getline(in, line);
                }
                i += 6;
            }
            else {
                std::getline(in, line);
                out << line << "\n";
            }
        }

        in.close();
        out.close();
        // swap temp and original save file
        std::remove("Save\\Save.txt");
        std::rename("Save\\Temp.txt", "Save\\Save.txt");
    }

    void UpdateLogic() {
        if (std::chrono::steady_clock::now() - lastMenuInput <= menInputBuffer) return;
        if (state == 0) {
            if (keys.up) {
                lastMenuInput = std::chrono::steady_clock::now();
                selection = max(0, selection - 1);
                fileSelection = selection;
            }
            if (keys.down) {
                lastMenuInput = std::chrono::steady_clock::now();
                selection = min(selecSize - 1, selection + 1);
                fileSelection = selection;
            }
            if (keys.space && name[selection] != "-") {
                lastMenuInput = std::chrono::steady_clock::now();
                selection = 0;
                state = 1;
                selecSize = 2;
            }
            if (keys.escape) {
                lastMenuInput = std::chrono::steady_clock::now();
                selection = 0;
                gameState = 1;
            }
            menuElements[1].xPosition = leftBorder + (92 * scalerX);
            menuElements[1].yPosition = (60 + (selection * 33)) * scalerY;
        }
        else if (state == 1) {
            if (keys.left) {
                lastMenuInput = std::chrono::steady_clock::now();
                selection = max(0, selection - 1);
            }
            if (keys.right) {
                lastMenuInput = std::chrono::steady_clock::now();
                selection = min(selecSize - 1, selection + 1);
            }
            if (keys.escape) {
                lastMenuInput = std::chrono::steady_clock::now();
                selection = 0;
                selecSize = 3;
                state = 0;
            }
            if (keys.space) {
                lastMenuInput = std::chrono::steady_clock::now();
                if (selection == 0) SaveGame();
                if (selection == 1) LoadGame();
            }
            menuElements[1].xPosition = leftBorder + (92 * scalerX) + (30 * selection);
            menuElements[1].yPosition = (164 * scalerY);
        }
    }

    void Render() {
        RenderObjMid(menuElements.at(0).frame, sysScreenX/2, sysScreenY/2);
        RenderObjLeft(Selection_Arrow, menuElements[1].xPosition, menuElements[1].yPosition);
        for (int i = 0; i < 3; i++) {
            RenderText(name[i], 105, 48 + (i * 33));
            if (dispAttr[i][0] == -1) RenderText("-", (105), 58 + (i * 33));
            else {
                std::string dispTime;
                time_t sec = dispAttr[i][0];
                if (sec == 0) dispTime = "--:--";
                else if (float(sec) / 3600 > 1) {
                    __int16 hours = min(999, int(sec / 3600));
                    dispTime = std::to_string(hours) + ":";
                    sec -= (3600 * hours);
                    if (sec < 600) dispTime += "0" + std::to_string(int(sec / 60));
                    else dispTime += std::to_string(int(sec / 60));
                }
                else {
                    if (sec > 600) {
                        dispTime = "0:" + std::to_string(int(sec / 60));
                    }
                    else {
                        dispTime = "0:0" + std::to_string(int(sec / 60));
                    }
                }
                RenderText(dispTime, (105), 58 + (i * 31.5));
            }
            RenderObjLeft(coin_s, leftBorder + (105 * scalerX), (69 + (i * 33)) * scalerY);
            if (dispAttr[i][1] == -1) RenderText("-", (114), 68 + (i * 33));
            else RenderText(std::to_string(dispAttr[i][1]), (114), 68 + (i * 33));
        }
    }
};

SaveMenu saveMenu;

class EquipmentMenu : public Menu {
public:
    int slotSelected = 0;
    int state = 0;
    int equipmentSelected = 0;
    EquipmentMenu() {
        selecSize = 4;
        menuElements.emplace_back(equip_Menu_Shell, sysScreenX / 2, sysScreenY / 2);
        menuElements.emplace_back(Selection_Arrow, 76, 60);
    }

    void UpdateLogic() {
        if (std::chrono::steady_clock::now() - lastMenuInput <= menInputBuffer) return;
        if (keys.escape) {
            lastMenuInput = std::chrono::steady_clock::now();
            if (state == 1) {
                selection = slotSelected;
                state = 0;
            }
            else if (state == 0) {
                selection = 0;
                gameState = 1;
            }
        }
        if (keys.up) {
            lastMenuInput = std::chrono::steady_clock::now();
            selection = max(0, selection - 1);
            if (state == 0) slotSelected = selection;
            if (state == 1) equipmentSelected = selection;
        }
        if (keys.down) {
            lastMenuInput = std::chrono::steady_clock::now();
            selection = min(selecSize - 1, selection + 1);
            if (state == 0) slotSelected = selection;
            if (state == 1) equipmentSelected = selection;
        }
        if (keys.space) {
            lastMenuInput = std::chrono::steady_clock::now();
            if (state == 0) {
                selection = 0;
                state = 1;
            }
            else if (state == 1) {
                player.equipment[slotSelected] = equipmentSelected;
                selection = slotSelected;
                state = 0;
            }
        }
    }

    void Render() {
        RenderObjMid(menuElements[0].frame, menuElements[0].xPosition, menuElements[0].yPosition);
        RenderObjLeft(menuElements[1].frame, leftBorder + (menuElements[1].xPosition * scalerX), scalerY * (menuElements[1].yPosition + (32 * selection)));
        if (state == 0) {
            RenderText("Weapon:", 86, 50);
            RenderText("Armor:", 86, 82);
            RenderText("Accessory 1:", 86, 114);
            RenderText("Accessory 2:", 86, 146);
            for (int i = 0; i < 4; i++) {
                int index = player.equipment[i];
                if (index != -1) {
                    RenderText(equipment[index].name, 89, 65 + (i * 32));
                    std::string text[2];
                    int textIndex = 0;
                    int size = 0;
                    if (equipment[index].statModifiers[0] > 0 && text[1].empty()) {
                        text[textIndex] = "Str +" + std::to_string(equipment[index].statModifiers[0]);
                        textIndex++;
                    }
                    if (equipment[index].statModifiers[1] > 0 && text[1].empty()) {
                        text[textIndex] = "Agi +" + std::to_string(equipment[index].statModifiers[1]);
                        textIndex++;
                    }
                    if (equipment[index].statModifiers[2] > 0 && text[1].empty()) {
                        text[textIndex] = "Int +" + std::to_string(equipment[index].statModifiers[2]);
                        textIndex++;
                    }
                    if (equipment[index].statModifiers[3] > 0 && text[1].empty()) {
                        text[textIndex] = "Wis +" + std::to_string(equipment[index].statModifiers[3]);
                        textIndex++;
                    }
                    if (equipment[index].statModifiers[4] > 0 && text[1].empty()) {
                        text[textIndex] = "Def +" + std::to_string(equipment[index].statModifiers[4]);
                        textIndex++;
                    }
                    if (equipment[index].statModifiers[5] > 0 && text[1].empty()) {
                        text[textIndex] = "MDf +" + std::to_string(equipment[index].statModifiers[5]);
                        textIndex++;
                    }
                    if (equipment[index].statModifiers[6] > 0 && text[1].empty()) {
                        text[textIndex] = "Lck +" + std::to_string(equipment[index].statModifiers[6]);
                        textIndex++;
                    }
                    RenderText(text[0], 150, 50 + (i * 32));
                    RenderText(text[1], 150, 65 + (i * 32));
                }
            }
        }
        else if (state == 1) {
            RenderText("GreatSword", 86, 50);
            RenderText("Mana Sword", 86, 82);
            RenderText("Cloth Armor", 86, 114);
            RenderText("Magic Ring", 86, 146);
        }
    }
};

EquipmentMenu equipMenu;

class PauseMenu : public Menu {
public:
    int selec = 0;
    std::chrono::milliseconds inBuff = std::chrono::milliseconds(150);
    PauseMenu() {
        menuElements.emplace_back(Pause_Menu, 156, 10);
        menuElements.emplace_back(Selection_Arrow, 188, 16);
    }

    void UpdateLogic() {
        if (std::chrono::steady_clock::now() - lastMenuInput <= menInputBuffer) return;
        if (keys.up) {
            lastMenuInput = std::chrono::steady_clock::now();
            selec = max(0, selec - 1);
        }
        if (keys.down) {
            lastMenuInput = std::chrono::steady_clock::now();
            selec = min(selecSize - 1, selec + 1);
        }
        menuElements[1].yPosition = 16 + (selec * 15);
        if (keys.space) {
            lastMenuInput = std::chrono::steady_clock::now();
            if (selec == 0) {
                equipMenu.selection = 0;
                gameState = 3;
            }
            if (selec == 1) {
                saveMenu.selection = 0;
                gameState = 2;
            }
        }
        if (keys.escape) {
            lastMenuInput = std::chrono::steady_clock::now();
            selection = 0;
            gameState = 0;
        }
    }

    void Render() {
        for (auto m : menuElements) {
            if (m.frame != Selection_Arrow) RenderObjLeft(m.frame, leftBorder + (m.xPosition * scalerX), m.yPosition * scalerY);
        }
        float a = RenderTextR("Equipment", 242, 14);
        float b = RenderTextR("Save/Load", 242, 29);
        switch (selec) {
        case 0:
            RenderObjLeft(menuElements[1].frame, leftBorder + ((232 - a) * scalerX), menuElements[1].yPosition * scalerY);
            break;
        case 1:
            RenderObjLeft(menuElements[1].frame, leftBorder + ((232 - b) * scalerX), menuElements[1].yPosition * scalerY);
            break;
        }
    }
};

PauseMenu pauseMen;

void Render(HWND hWnd)
{
    if (renderTarget)
    {
        renderTarget->BeginDraw();
        renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));
        // Keeps stuff from being rendered outside boundaries
        D2D1_RECT_F aspectEnforcer = D2D1::RectF(leftBorder, 0, rightBorder, sysScreenY);

        // Push the clipping rectangle onto the render target
        renderTarget->PushAxisAlignedClip(aspectEnforcer, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
        HRESULT hr = S_OK;
        if (gameState != 99) {
            // Render Environment
            RenderObjLeft(environments.at(currentEnvID - 1).frame, leftBorder, 0); 
            
            // Render Enemies
            for (int i = 0; i < enemies.size(); i++)
            {
                RenderObjLeft(enemies[i].frame, enemies[i].xPosition, enemies[i].yPosition);

                LPCWSTR file_Name;
                if (enemies.at(i).damageTaken)
                {
                    file_Name = playerHitBox;
                }
                else
                {
                    file_Name = playerHurtBox;
                }

                ID2D1Bitmap* enemyHurtBoxBitmap = memSprites[file_Name];

                // Draw the hurtboxbitmap
                /*if (enemyHurtBoxBitmap)
                {
                    D2D1_SIZE_F size;
                    size.width = enemies.at(i).hurtbox.right - enemies.at(i).hurtbox.left;
                    size.height = enemies.at(i).hurtbox.bottom - enemies.at(i).hurtbox.top;
                    D2D1_RECT_F destRect = D2D1::RectF(enemies.at(i).hurtbox.left, enemies.at(i).hurtbox.top,
                        size.width + enemies.at(i).hurtbox.left, size.height + enemies.at(i).hurtbox.top);
                    renderTarget->DrawBitmap(enemyHurtBoxBitmap, destRect);
                }*/
            } 

            // Get weapon bitmap
            ID2D1Bitmap* playerWeaponFrameBitmap = memSprites[player.weaponFileName];

            // Get the player bitmap
            ID2D1Bitmap* playerFrameBitmap = memSprites[player.frame];

            // Render weapon
            if (playerWeaponFrameBitmap)
            {
                ID2D1Bitmap* hitbox = memSprites[playerHitBox];

                // Draw the hurtboxbitmap
                /*if (hitbox)
                {
                    D2D1_SIZE_F size;
                    size.width = player.hitbox.right - player.hitbox.left;
                    size.height = player.hitbox.bottom - player.hitbox.top;
                    D2D1_RECT_F destRect = D2D1::RectF(player.hitbox.left, player.hitbox.top,
                        size.width + player.hitbox.left, size.height + player.hitbox.top);
                    renderTarget->DrawBitmap(hitbox, destRect);
                }*/

                // Draw Weapon
                D2D1_SIZE_F size = playerWeaponFrameBitmap->GetSize();
                D2D1_SIZE_F playerSize = playerFrameBitmap->GetSize();
                D2D1_POINT_2F midpoint = D2D1::Point2F((player.xPosition + ((playerSize.width * scalerX) / 2)), (player.yPosition + (playerSize.height * scalerY) / 2));
                D2D1_MATRIX_3X2_F rotate = D2D1::Matrix3x2F::Rotation(player.angleDegrees, midpoint);
                renderTarget->SetTransform(rotate);
                D2D1_RECT_F destRect = D2D1::RectF(player.weaponXPosition, player.weaponYPosition,
                    (size.width * scalerX) + player.weaponXPosition, (size.height * scalerY) + player.weaponYPosition);
                renderTarget->DrawBitmap(playerWeaponFrameBitmap, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

                

                renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
            }

            // Render Player Projectiles
            for (auto p : playerProjectiles) {
                ID2D1Bitmap* b = memSprites[p.frame];
                D2D1_SIZE_F size = b->GetSize();
                D2D1_POINT_2F midpoint = D2D1::Point2F((p.xPosition + ((size.width * scalerX) / 2)), (p.yPosition + (size.height * scalerY) / 2));
                D2D1_MATRIX_3X2_F rotate = D2D1::Matrix3x2F::Rotation(p.angleDegrees, midpoint);
                renderTarget->SetTransform(rotate);
                RenderObjLeft(p.frame, p.xPosition, p.yPosition);
                renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
            }

            // Render player
            if (playerFrameBitmap)
            {
                int xOffset(2), yOffset(18);
                ID2D1Bitmap* pShadow = memSprites[player_shadow];
                if (player.angleDegrees == 90.0) {
                    pShadow = memSprites[player_shadow_sideways];
                }
                else if (player.angleDegrees == 270.0) {
                    pShadow = memSprites[player_shadow_sideways];
                    xOffset = 3;
                }
                if (pShadow) {
                    D2D1_SIZE_F size = pShadow->GetSize();
                    D2D1_RECT_F destRect = D2D1::RectF(player.xPosition + (xOffset * scalerX), player.yPosition + (18 * scalerY),
                        ((xOffset + size.width) * scalerX) + player.xPosition, ((18 + size.height) * scalerY) + player.yPosition);
                    renderTarget->DrawBitmap(pShadow, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
                }

                D2D1_SIZE_F size = playerFrameBitmap->GetSize();
                D2D1_RECT_F destRect = D2D1::RectF(player.xPosition, player.yPosition,
                    (size.width * scalerX) + player.xPosition, (size.height * scalerY) + player.yPosition);
                renderTarget->DrawBitmap(playerFrameBitmap, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

                
            }

            // Get hurtbox bitmap
            ID2D1Bitmap* playerHurtBoxBitmap = memSprites[playerHurtBox];

            /*
            // Render hurtbox
            if (playerHurtBoxBitmap)
            {
                D2D1_SIZE_F size;
                size.width = player.hurtbox.right - player.hurtbox.left;
                size.height = player.hurtbox.bottom - player.hurtbox.top;
                D2D1_RECT_F destRect = D2D1::RectF(player.hurtbox.left, player.hurtbox.top,
                size.width + player.hurtbox.left, size.height + player.hurtbox.top);
                renderTarget->DrawBitmap(playerHurtBoxBitmap, destRect);
            }*/

            // Text format for MP & HP
            hr = DWriteCreateFactory(
                DWRITE_FACTORY_TYPE_SHARED,
                __uuidof(IDWriteFactory),
                reinterpret_cast<IUnknown**>(&pDWriteFactory)
            );
            if (SUCCEEDED(hr)) {
                hr = pDWriteFactory->CreateTextFormat(
                    L"System",
                    NULL,
                    DWRITE_FONT_WEIGHT_BOLD,
                    DWRITE_FONT_STYLE_NORMAL,
                    DWRITE_FONT_STRETCH_NORMAL,
                    30.0f,
                    L"en-us",
                    &pTextFormat
                );
            }

            if (SUCCEEDED(hr)) {
                hr = pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
            }

            // Text color for MP & HP
            if (SUCCEEDED(hr)) {
                hr = renderTarget->CreateSolidColorBrush(
                    D2D1::ColorF(D2D1::ColorF::White),
                    &pBrush
                );
            }

            // Get HP Bar filling bitmap
            ID2D1Bitmap* playerHPBarFilling = memSprites[hpBarFilling];

            // Render HP Bar Filling
            if (playerHPBarFilling)
            {
                D2D1_SIZE_F size = playerHPBarFilling->GetSize();

                // Get ratio based on player's current HP
                double hpRatio = player.HP / player.maxHP;
                unsigned int hpBarWidth = size.width * hpRatio;

                D2D1_RECT_F srcRect = D2D1::RectF(0, 0, hpBarWidth, size.height);

                double h = size.height;

                D2D1_RECT_F destRect = D2D1::RectF(rightBorder - (((size.width) + 5) * scalerX), 4 * scalerY,
                    rightBorder - (((size.width) + 5) * scalerX) + (hpBarWidth * scalerX), (4 + h) * scalerX);

                renderTarget->DrawBitmap(playerHPBarFilling, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
            }

            // Get MP Bar Filling bitmap
            ID2D1Bitmap* playerMPBarFilling = memSprites[mpBarFilling];

            // Render MP Bar Filling
            if (playerMPBarFilling)
            {
                D2D1_SIZE_F size = playerMPBarFilling->GetSize();

                double mpRatio = player.MP / player.maxMP;
                unsigned int mpBarWidth = size.width * mpRatio;
                double h = size.height;

                D2D1_RECT_F srcRect = D2D1::RectF(0, 0, mpBarWidth, size.height);

                D2D1_RECT_F destRect = D2D1::RectF(rightBorder - (((size.width) + 5) * scalerX), 17 * scalerY,
                    rightBorder - (((size.width) + 5) * scalerX) + (mpBarWidth * scalerX), (17 + h) * scalerX);

                renderTarget->DrawBitmap(playerMPBarFilling, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
            }

            // EXP Bar Filling
            ID2D1Bitmap* playerEXPBarFilling = memSprites[expBarFilling];

            if (playerEXPBarFilling)
            {
                D2D1_SIZE_F size = playerEXPBarFilling->GetSize();

                double expRatio = player.exp / player.levelup;
                if (expRatio > 1) {
                    expRatio = 1;
                }
                unsigned int expBarWidth = size.width * expRatio;

                D2D1_RECT_F srcRect = D2D1::RectF(0, 0, expBarWidth, size.height);

                D2D1_RECT_F destRect = D2D1::RectF(rightBorder - (((size.width) + 5) * scalerX), 31 * scalerY,
                    rightBorder - (((size.width) + 5) * scalerX) + (expBarWidth * scalerX), (31 + size.height) * scalerX);

                renderTarget->DrawBitmap(playerEXPBarFilling, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
            }

            // UI Shell
            ID2D1Bitmap* UIShellBMP = memSprites[UI_Shell];
            if (UIShellBMP) {
                D2D1_SIZE_F size = UIShellBMP->GetSize();
                D2D1_RECT_F destRect = D2D1::RectF(leftBorder, 0, rightBorder, sysScreenY);
                renderTarget->DrawBitmap(UIShellBMP, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
            }

            // Skill Panes
            RenderObjLeft(skillPanes, leftBorder + (2 * scalerX), (2 * scalerX));

            for (auto prop : environments.at(currentEnvID - 1).props) {
                RenderObjLeft(prop.frame, prop.xPosition, prop.yPosition);
            }

            // FPS Counter
            hr = DWriteCreateFactory(
                DWRITE_FACTORY_TYPE_SHARED,
                __uuidof(IDWriteFactory),
                reinterpret_cast<IUnknown**>(&pDWriteFactory)
            );
            if (SUCCEEDED(hr)) {
                hr = pDWriteFactory->CreateTextFormat(
                    L"Arial",
                    NULL,
                    DWRITE_FONT_WEIGHT_NORMAL,
                    DWRITE_FONT_STYLE_NORMAL,
                    DWRITE_FONT_STRETCH_NORMAL,
                    20.0f,
                    L"en-us",
                    &pTextFormat
                );
            }

            // Create the brush for text
            if (SUCCEEDED(hr)) {
                hr = renderTarget->CreateSolidColorBrush(
                    D2D1::ColorF(D2D1::ColorF::White),
                    &pBrush
                );
            }



            // If the player is in level up fanfare
            if (player.inLevelUpSequence == true || player.inLevelUpFanfare == true) {

                if (player.lastLevelUpOverworldTextFileName == nullptr) {
                    player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_1;
                    player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                }

                if ((std::chrono::steady_clock::now() - player.lastLevelUpOverworldTextTime) >= std::chrono::milliseconds(64)) {

                    if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_1) {
                        player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_2;
                        player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                        player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                    }
                    else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_2) {
                        player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_3;
                        player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                        player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                    }
                    else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_3) {
                        player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_4;
                        player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                        player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                    }
                    else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_4) {
                        player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_5;
                        player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                        player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                    }
                    else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_5) {
                        player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_6;
                        player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                        player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                    }
                    else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_6) {
                        player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_7;
                        player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                        player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                    }
                    else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_7) {
                        player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_8;
                        player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                        player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                    }
                    else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_8) {
                        player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_9;
                        player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                        player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                    }
                    else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_9 &&
                        std::chrono::steady_clock::now() - player.lastLevelUpOverworldTextTime >= std::chrono::milliseconds(250)) {
                        player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_1;
                        player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                        player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                    }


                }

                // Get level up overworld text bitmap
                ID2D1Bitmap* level_Up_Overworld_Text = memSprites[player.levelUpOverworldTextFileName];


                // Render level up overworld text
                if (level_Up_Overworld_Text)
                {
                    D2D1_SIZE_F size = level_Up_Overworld_Text->GetSize();

                    /*if ((std::chrono::steady_clock::now() - player.timePointofLastBob) > std::chrono::milliseconds(250)) {
                        if (player.lastBobWasZero) {
                            player.bobberUpper = 1;
                            player.lastBobWasZero = false;
                        } else {
                            player.bobberUpper = 0;
                            player.lastBobWasZero = true;
                        }
                        player.timePointofLastBob = std::chrono::steady_clock::now();
                    }*/
                    D2D1_RECT_F destRect = D2D1::RectF(player.xPosition - (14 * scalerX), player.yPosition + ((4 - player.bobberUpper) * scalerY),
                        player.xPosition + ((size.width - 14) * scalerX), player.yPosition + ((size.height + 4 - player.bobberUpper) * scalerY));
                    renderTarget->DrawBitmap(level_Up_Overworld_Text, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
                }
            }

            // If the player has leveled up
            if (player.inLevelUpSequence == true && player.inLevelUpFanfare == false) {
                // Get level up screen shell bitmap
                ID2D1Bitmap* shellBitmap = memSprites[Focused_Level_Up_Screen_Shell];

                // Render level up screen shell
                if (shellBitmap)
                {
                    D2D1_SIZE_F size = shellBitmap->GetSize();
                    D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (65 * scalerX), 28 * scalerY,
                        ((leftBorder + (65 * scalerX))) + (size.width * scalerX), ((size.height + 28) * scalerY));
                    renderTarget->DrawBitmap(shellBitmap, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
                }

                int i = 74;
                int j[7] = {
                    40,
                    57,
                    74,
                    91,
                    108,
                    125,
                    142
                };
                RenderText("Strength", i, j[0]);
                RenderText("Agility", i, j[1]);
                RenderText("Intelligence", i, j[2]);
                RenderText("Wisdom", i, j[3]);
                RenderText("Defense", i, j[4]);
                RenderText("M Defense", i, j[5]);
                RenderText("Luck", i, j[6]);

                // Render Before stats
                ID2D1Bitmap* strStat1;
                ID2D1Bitmap* strStat2;
                ID2D1Bitmap* strStat3;
                TranslateStatstoBitmap(player.strength - player.lvlUpStats[0], strStat1, strStat2, strStat3);
                ID2D1Bitmap* agiStat1;
                ID2D1Bitmap* agiStat2;
                ID2D1Bitmap* agiStat3;
                TranslateStatstoBitmap(player.agility - player.lvlUpStats[1], agiStat1, agiStat2, agiStat3);
                ID2D1Bitmap* intStat1;
                ID2D1Bitmap* intStat2;
                ID2D1Bitmap* intStat3;
                TranslateStatstoBitmap(player.intelligence - player.lvlUpStats[2], intStat1, intStat2, intStat3);
                ID2D1Bitmap* wisStat1;
                ID2D1Bitmap* wisStat2;
                ID2D1Bitmap* wisStat3;
                TranslateStatstoBitmap(player.wisdom - player.lvlUpStats[3], wisStat1, wisStat2, wisStat3);
                ID2D1Bitmap* defStat1;
                ID2D1Bitmap* defStat2;
                ID2D1Bitmap* defStat3;
                TranslateStatstoBitmap(player.defense - player.lvlUpStats[4], defStat1, defStat2, defStat3);
                ID2D1Bitmap* mDefStat1;
                ID2D1Bitmap* mDefStat2;
                ID2D1Bitmap* mDefStat3;
                TranslateStatstoBitmap(player.magicDefense - player.lvlUpStats[5], mDefStat1, mDefStat2, mDefStat3);
                ID2D1Bitmap* luckStat1;
                ID2D1Bitmap* luckStat2;
                ID2D1Bitmap* luckStat3;
                TranslateStatstoBitmap(player.luck - player.lvlUpStats[6], luckStat1, luckStat2, luckStat3);
                i = 155;
                for (auto& num : j) {
                    num++;
                }
                RenderStatsRight(strStat1, strStat2, strStat3, i, j[0]);
                RenderStatsRight(agiStat1, agiStat2, agiStat3, i, j[1]);
                RenderStatsRight(intStat1, intStat2, intStat3, i, j[2]);
                RenderStatsRight(wisStat1, wisStat2, wisStat3, i, j[3]);
                RenderStatsRight(defStat1, defStat2, defStat3, i, j[4]);
                RenderStatsRight(mDefStat1, mDefStat2, mDefStat3, i, j[5]);
                RenderStatsRight(luckStat1, luckStat2, luckStat3, i, j[6]);

                // Render After Stats
                i = 185;
                TranslateStatstoBitmap(player.strength, strStat1, strStat2, strStat3);
                TranslateStatstoBitmap(player.agility, agiStat1, agiStat2, agiStat3);
                TranslateStatstoBitmap(player.intelligence, intStat1, intStat2, intStat3);
                TranslateStatstoBitmap(player.wisdom, wisStat1, wisStat2, wisStat3);
                TranslateStatstoBitmap(player.defense, defStat1, defStat2, defStat3);
                TranslateStatstoBitmap(player.magicDefense, mDefStat1, mDefStat2, mDefStat3);
                TranslateStatstoBitmap(player.luck, luckStat1, luckStat2, luckStat3);

                RenderStatsRight(strStat1, strStat2, strStat3, i, j[0]);
                RenderStatsRight(agiStat1, agiStat2, agiStat3, i, j[1]);
                RenderStatsRight(intStat1, intStat2, intStat3, i, j[2]);
                RenderStatsRight(wisStat1, wisStat2, wisStat3, i, j[3]);
                RenderStatsRight(defStat1, defStat2, defStat3, i, j[4]);
                RenderStatsRight(mDefStat1, mDefStat2, mDefStat3, i, j[5]);
                RenderStatsRight(luckStat1, luckStat2, luckStat3, i, j[6]);

                // Render Arrows
                i = 161;
                for (auto& num : j) {
                    num++;
                }
                RenderText(":right_arrow", i, j[0]);
                RenderText(":right_arrow", i, j[1]);
                RenderText(":right_arrow", i, j[2]);
                RenderText(":right_arrow", i, j[3]);
                RenderText(":right_arrow", i, j[4]);
                RenderText(":right_arrow", i, j[5]);
                RenderText(":right_arrow", i, j[6]);

                // Get back button bitmap
                ID2D1Bitmap* confirmButtonBitmap;
                LPCWSTR filename = player.lastConfirmButtonFile;
                if (player.statSelection == 9 &&
                    (std::chrono::steady_clock::now() - player.backButtonAnimationInterval > std::chrono::milliseconds(500)))
                {
                    player.backButtonAnimationInterval = std::chrono::steady_clock::now();
                    if (player.lastConfirmButtonFile == Level_Up_Confirm_Button_Unpressed) {
                        filename = Level_Up_Confirm_Button_Pressed;
                        player.lastConfirmButtonFile = Level_Up_Confirm_Button_Pressed;
                    }
                    else {
                        filename = Level_Up_Confirm_Button_Unpressed;
                        player.lastConfirmButtonFile = Level_Up_Confirm_Button_Unpressed;
                    }
                }
                if (player.statSelection != 9) {
                    filename = Level_Up_Confirm_Button_Unpressed;
                    player.lastConfirmButtonFile = Level_Up_Confirm_Button_Unpressed;
                }

                confirmButtonBitmap = memSprites[filename];

                // Render back button
                if (confirmButtonBitmap)
                {

                    D2D1_SIZE_F size = confirmButtonBitmap->GetSize();
                    D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (110 * scalerX), 167 * scalerY,
                        ((leftBorder + (110 * scalerX))) + (size.width * scalerX), ((size.height + 167) * scalerY));
                    renderTarget->DrawBitmap(confirmButtonBitmap, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
                }

                //// Get confirm bitmap
                //ID2D1Bitmap* confirmButton = memSprites[Level_Up_Confirm_Button_Unpressed];
                //// Render confirm button
                //if (focusedLevelUpBitmap)
                //{
                //    D2D1_SIZE_F size = confirmButton->GetSize();
                //    D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (64 * scalerX), 1 * scalerY,
                //        ((leftBorder + (64 * scalerX))) + (size.width * scalerX), ((size.height + 1) * scalerY));
                //    renderTarget->DrawBitmap(confirmButton, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
                //}


            }

            //// Weapn Hitbox
            //ID2D1Bitmap* playerHitBoxBitmap = memSprites[playerHitBox];

            //if (playerHitBoxBitmap && playerWeaponFrameBitmap)
            //{
            //    D2D1_SIZE_F size = playerWeaponFrameBitmap->GetSize();
            //    D2D1_RECT_F destRect = D2D1::RectF(player.weaponXPosition, player.weaponYPosition,
            //        (size.width * scalerX) + player.weaponXPosition, (size.height * scalerY) + player.weaponYPosition);
            //    renderTarget->DrawBitmap(playerHitBoxBitmap, destRect);
            //}

            //if (pTextFormat && pBrush)
            //{
            //    auto now = std::chrono::steady_clock::now();
            //    std::chrono::duration<double> elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdate);
            //    if (elapsed.count() >= 0.25) {
            //        fps = frameCount / elapsed.count();
            //        frameCount = 0;
            //        lastUpdate = now;
            //    }

            //    // Render FPS counter
            //    WCHAR buffer[32];
            //    swprintf_s(buffer, L"FPS: %.2f", fps);
            //    D2D1_RECT_F layoutRect = D2D1::RectF(sysScreenX - 100, 0, sysScreenX, 20);
            //    renderTarget->DrawText(
            //        buffer,
            //        wcslen(buffer),
            //        pTextFormat,
            //        layoutRect,
            //        pBrush
            //    );

            //}
        }
        if (gameState == 1 || gameState == 2) pauseMen.Render();
        if (gameState == 2) saveMenu.Render();
        if (gameState == 3) equipMenu.Render();
        else if (gameState == 99) RenderObjLeft(environments[currentEnvID].frame, 0, 0);

        // Pop the clipping rectangle off the render target
        renderTarget->PopAxisAlignedClip();

        hr = renderTarget->EndDraw();

        if (hr == D2DERR_RECREATE_TARGET)
        {
            ReleaseMemory();
        }
    }
}

//-----------------------------------------------
// Consolidatory Functions for UpdateGameLogic()
//-----------------------------------------------

void InitializeAssets() {
    std::discrete_distribution<int> range({ 7, 3, 1 });
    player.strength = 3 + range(generator);
    player.agility = 3 + range(generator);
    player.intelligence = 3 + range(generator);
    player.wisdom = 3 + range(generator);
    player.defense = 3 + range(generator);
    player.magicDefense = 3 + range(generator);
    player.luck = 3 + range(generator);


    playerStationaryUpBasicAttackFrames[0] = L"Sprites\\Player\\playerstationaryupbasicattack0.png";
    playerStationaryUpBasicAttackFrames[1] = L"Sprites\\Player\\playerstationaryupbasicattack1.png";
    playerStationaryUpBasicAttackFrames[2] = L"Sprites\\Player\\playerstationaryupbasicattack2.png";
    playerStationaryUpBasicAttackFrames[3] = L"Sprites\\Player\\playerstationaryupbasicattack3.png";
    playerStationaryUpBasicAttackFrames[4] = L"Sprites\\Player\\playerstationaryupbasicattack4.png";
    playerStationaryUpBasicAttackFrames[5] = L"Sprites\\Player\\playerstationaryupbasicattack5.png";
    playerStationaryUpBasicAttackFrames[6] = L"Sprites\\Player\\playerstationaryupbasicattack6.png";
    playerStationaryUpBasicAttackFrames[7] = L"Sprites\\Player\\playerstationaryupbasicattack7.png";
    playerStationaryUpBasicAttackFrames[8] = L"Sprites\\Player\\playerstationaryupbasicattack8.png";

    testSwordBasicAttack[0] = L"Sprites\\Weapons\\testswordbasicattackup0.png";
    testSwordBasicAttack[1] = L"Sprites\\Weapons\\testswordbasicattackup1.png";
    testSwordBasicAttack[2] = L"Sprites\\Weapons\\testswordbasicattackup2.png";
    testSwordBasicAttack[3] = L"Sprites\\Weapons\\testswordbasicattackup3.png";
    testSwordBasicAttack[4] = L"Sprites\\Weapons\\testswordbasicattackup4.png";
    testSwordBasicAttack[5] = L"Sprites\\Weapons\\testswordbasicattackup5.png";
    testSwordBasicAttack[6] = L"Sprites\\Weapons\\testswordbasicattackup6.png";
    testSwordBasicAttack[7] = L"Sprites\\Weapons\\testswordbasicattackup7.png";
    testSwordBasicAttack[8] = L"Sprites\\Weapons\\testswordbasicattackup8.png";
    srand(time(NULL));

    // Load all Sprites
    StoreSpriteFileNames(spriteData);

    // Load Enemy Info
    populateEnemyExpList();

    // 1: Front Yard
    environments.emplace_back(BG_home_f, environments.size() + 1);
    environments.back().AddDoor(40, 104, 0, 1, -1, 202, 2);
    environments.back().AddDoor(40, 255, 223, 224, -1, 1, 3);
    environments.back().AddDoor(160, 181, 25, 51, 121, 202, 5);

    // 2: Back Yard
    environments.emplace_back(BG_home_b, environments.size() + 1);
    environments.back().AddDoor(40, 104, 223, 224, -1, 1, 1);
    environments.back().AddDoor(168, 186, 185, 186, 120.5, 21, 5);
    environments.back().AddProp(BG_home_roof, 104, 171);

    // 3: Home Path 1
    environments.emplace_back(BG_home_p1, environments.size() + 1);
    environments.back().AddDoor(40, 255, 0, 1, -1, 202, 1);
    environments.back().AddDoor(40, 255, 223, 224, -1, 1, 4);

    // 4: Home Path 2
    environments.emplace_back(BG_home_p2, environments.size() + 1);
    environments.back().AddDoor(40, 255, 0, 1, -1, 202, 3);
    environments.back().AddDoor(148, 193, 223, 224, 125, 1, 6);

    // 5: Home Interior 1
    environments.emplace_back(BG_home_interior_1, environments.size() + 1);
    environments.back().AddDoor(118, 138, 223, 224, 164, 51, 1);
    environments.back().AddDoor(118, 138, 0, 20, 166.5, 163, 2);

    // 6: Forest 1
    environments.emplace_back(Forest_1, environments.size() + 1);
    environments.back().AddDoor(111, 145, 0, 1, 164, 202, 4);
    environments.back().AddDoor(105, 145, 223, 224, -1, 1, 7);
    environments.back().AddDoor(0, 1, 97, 135, 241, -1, 10);
    environments.at(environments.size() - 1).enemyData.emplace_back(0, 74, 34, false);
    environments.at(environments.size() - 1).enemyData.emplace_back(0, 44, 170, false);

    // 7: Forest 2
    environments.emplace_back(Forest_2, environments.size() + 1);
    environments.back().AddDoor(107, 147, 0, 1, -1, 202, 6);
    environments.back().AddDoor(254, 255, 105, 156, 1, -1, 8);
    environments.back().AddDoor(0, 1, 102, 149, 241, -1, 11);

    // 8: Forest 3
    environments.emplace_back(Forest_4, environments.size() + 1);
    environments.back().AddDoor(0, 1, 105, 156, 241, -1, 7);
    environments.back().AddDoor(112, 168, 0, 1, -1, 202, 9);

    // 9: Forest 4
    environments.emplace_back(Forest_5, environments.size() + 1);
    environments.back().AddDoor(108, 163, 223, 224, -1, 1, 8);

    // 10: Forest 5
    environments.emplace_back(Forest_3, environments.size() + 1);
    environments.back().AddDoor(254, 255, 87, 138, 1, -1, 6);

    // 11: Forest 6
    environments.emplace_back(Forest_6, environments.size() + 1);
    environments.back().AddDoor(254, 255, 102, 148, 1, -1, 7);
    environments.back().AddDoor(91, 134, 223, 224, -1, 1, 12);

    // 12: Forest 7
    environments.emplace_back(Forest_7, environments.size() + 1);
    environments.back().AddDoor(91, 138, 0, 1, -1, 202, 11);
    environments.back().AddDoor(91, 141, 223, 224, -1, 1, 13);

    // 13: Forest 8
    environments.emplace_back(Forest_8, environments.size() + 1);
    environments.back().AddDoor(89, 143, 0, 1, -1, 202, 12);
    environments.back().AddDoor(254, 255, 114, 175, 1, -1, 14);

    // 14: Forest 9
    environments.emplace_back(Forest_9, environments.size() + 1);
    environments.back().AddDoor(0, 1, 112, 199, 241, -1, 13);
    environments.back().AddDoor(254, 255, 117, 199, 1, -1, 15);
    environments.back().AddDoor(98, 143, 0, 1, -1, 202, 16);
    environments.back().AddDoor(80, 161, 223, 224, -1, 1, 17);

    // 15: Forest 10
    environments.emplace_back(Forest_10, environments.size() + 1);
    environments.back().AddDoor(0, 1, 107, 145, 202, -1, 14);

    // 16: Forest 11
    environments.emplace_back(Forest_11, environments.size() + 1);
    environments.back().AddDoor(0, 255, 223, 224, 114, 1, 14);

    // 17: Forest 12
    environments.emplace_back(Forest_12, environments.size() + 1);
    environments.back().AddDoor(80, 161, 0, 1, -1, 202, 14);
    environments.back().AddDoor(99, 180, 223, 224, -1, 1, 18);

    // 18: Forest 13
    environments.emplace_back(Forest_13, environments.size() + 1);
    environments.back().AddDoor(85, 179, 0, 1, -1, 202, 17);
    environments.back().AddDoor(254, 255, 104, 172, -1, -1, 19);

    // 19: End Demo Screen
    environments.emplace_back(Demo_End_Screen, environments.size() + 1);

    std::vector<bool> calendar(365, false);

    lastUpdate = std::chrono::steady_clock::now();

    equipment[0] = Equipment("GreatSword", 7, 0, 0, 0, 3, 0, 0);
    equipment[1] = Equipment("Mana Sword", 7, 0, 7, 0, 0, 0, 0);
    equipment[2] = Equipment("Cloth Outfit", 0, 0, 0, 0, 2, 1, 0);
    equipment[3] = Equipment("Magic Ring", 0, 0, 5, 4, 0, 0, 0);

    player.equipment[0] = 0;
    player.equipment[1] = 2;
    player.equipment[2] = -1;
    player.equipment[3] = -1;
}

void HandleLevelUpSequence() {
    if (player.inLevelUpFanfare) {
        if ((std::chrono::steady_clock::now() - player.levelUpFanfareBegin) >= std::chrono::seconds(1)) {
            player.inLevelUpFanfare = false;
        }
        if (!player.statsUpdated) {
            std::discrete_distribution<int> range({ 7, 3, 1 });
            for (unsigned __int8 i = 0; i < sizeof(player.lvlUpStats); i++) {
                player.lvlUpStats[i] = 1 + range(generator);
            }
            player.maxHP *= 1.10;
            player.HP = player.maxHP;
            player.MP *= 1.1;
            player.MP = player.maxMP;
            player.strength += player.lvlUpStats[0];
            player.agility += player.lvlUpStats[1];
            player.intelligence += player.lvlUpStats[2];
            player.wisdom += player.lvlUpStats[3];
            player.defense += player.lvlUpStats[4];
            player.magicDefense += player.lvlUpStats[5];
            player.luck += player.lvlUpStats[6];
            player.statsUpdated = true;
        }

    }
    else
    {
        if (player.mId == 9 && keys.space) {

            player.mId = 0;
            player.inLevelUpSequence = false;
            player.exp = player.exp - player.levelup;
            player.levelup *= 1.33;
            player.statsUpdated = false;
            return;
        }
        if (player.mId == 10) {
            if ((!player.statSelected && (std::chrono::steady_clock::now() - player.timeSinceLastStatSelection >= std::chrono::milliseconds(150)))
                || ((keys.space && player.statSelected) && (std::chrono::steady_clock::now() - player.timeSinceLastStatSelection >= std::chrono::milliseconds(300)))
                || ((player.statSelected && !keys.space) && (std::chrono::steady_clock::now() - player.timeSinceLastStatSelection > std::chrono::milliseconds(150)))
                || ((keys.lastKeyPressed == "down" || keys.lastKeyPressed == "up") &&
                    ((std::chrono::steady_clock::now() - player.timeIncrementingNumberwasHeld >= std::chrono::seconds(1)) &&
                        (std::chrono::steady_clock::now() - player.timeSinceLastStatSelection >= std::chrono::milliseconds(50))))
                || ((keys.lastKeyPressed == "down" || keys.lastKeyPressed == "up") &&
                    ((std::chrono::steady_clock::now() - player.timeIncrementingNumberwasHeld >= std::chrono::seconds(3)) &&
                        (std::chrono::steady_clock::now() - player.timeSinceLastStatSelection >= std::chrono::milliseconds(25))))
                || ((keys.lastKeyPressed == "down" || keys.lastKeyPressed == "up") &&
                    ((std::chrono::steady_clock::now() - player.timeIncrementingNumberwasHeld >= std::chrono::seconds(10)) &&
                        (std::chrono::steady_clock::now() - player.timeSinceLastStatSelection >= std::chrono::milliseconds(8)))))
            {
                if (!player.statSelected)
                {
                    if (keys.down) {
                        player.statSelection = min(player.statSelection + 1, 9);
                        player.timeSinceLastStatSelection = std::chrono::steady_clock::now();
                    }
                    if (keys.up) {
                        player.statSelection = max(player.statSelection - 1, 0);
                        player.timeSinceLastStatSelection = std::chrono::steady_clock::now();
                    }
                }
                if (keys.space) {
                    if (player.statSelection == 9) {
                        player.inLevelUpSequence = false;
                        player.inLevelUpFanfare = false;
                        player.exp = 0;
                        player.levelup *= 1.10;
                        return;
                    }
                    player.timeSinceLastStatSelection = std::chrono::steady_clock::now();
                    if (player.statSelected == false) {
                        player.statSelected = true;
                    }
                    else {
                        player.statSelected = false;
                    }
                }
                if (player.statSelected) {
                    if (keys.up) {
                        player.timeSinceLastStatSelection = std::chrono::steady_clock::now();
                        if (keys.lastKeyPressed != "up")
                        {
                            player.timeIncrementingNumberwasHeld = std::chrono::steady_clock::now();
                        }
                        keys.lastKeyPressed = "up";
                        switch (player.statSelection)
                        {
                        case 0:
                            player.strength = min(player.strength + 1, 999);
                            break;
                        case 1:
                            player.dexterity = min(player.dexterity + 1, 999);
                            break;
                        case 2:
                            player.intelligence = min(player.intelligence + 1, 999);
                            break;
                        case 3:
                            player.wisdom = min(player.wisdom + 1, 999);
                            break;
                        case 4:
                            player.defense = min(player.defense + 1, 999);
                            break;
                        case 5:
                            player.magicDefense = min(player.magicDefense + 1, 999);
                            break;
                        case 6:
                            player.trueDefense = min(player.trueDefense + 1, 999);
                            break;
                        case 7:
                            player.agility = min(player.agility + 1, 999);
                            break;
                        case 8:
                            player.luck = min(player.luck + 1, 999);
                            break;
                        }
                    }
                    if (keys.down) {
                        player.timeSinceLastStatSelection = std::chrono::steady_clock::now();
                        if (keys.lastKeyPressed != "down")
                        {
                            player.timeIncrementingNumberwasHeld = std::chrono::steady_clock::now();
                        }
                        keys.lastKeyPressed = "down";
                        switch (player.statSelection)
                        {
                        case 0:
                            player.strength = max(player.strength - 1, startingStats[player.statSelection]);
                            break;
                        case 1:
                            player.dexterity = max(player.dexterity - 1, startingStats[player.statSelection]);
                            break;
                        case 2:
                            player.intelligence = max(player.intelligence - 1, startingStats[player.statSelection]);
                            break;
                        case 3:
                            player.wisdom = max(player.wisdom - 1, startingStats[player.statSelection]);
                            break;
                        case 4:
                            player.defense = max(player.defense - 1, startingStats[player.statSelection]);
                            break;
                        case 5:
                            player.magicDefense = max(player.magicDefense - 1, startingStats[player.statSelection]);
                            break;
                        case 6:
                            player.trueDefense = max(player.trueDefense - 1, startingStats[player.statSelection]);
                            break;
                        case 7:
                            player.agility = max(player.agility - 1, startingStats[player.statSelection]);
                            break;
                        case 8:
                            player.luck = max(player.luck - 1, startingStats[player.statSelection]);
                            break;
                        }
                    }
                    if (!keys.up && !keys.down)
                    {
                        keys.lastKeyPressed = "";
                    }
                }
            }
        }
    }
}

void UpdateProjectileLogic(double deltaSeconds) {
    // Player Projectile Logic
    for (int i = 0; i < playerProjectiles.size(); i++) {
        int index = i;
        playerProjectiles.at(i).UpdateHitBox();
        for (int j = 0; j < enemies.size(); j++) {
            if (playerProjectiles.at(i).CheckCollision(enemies.at(j))) {
                player.dmgLagStarted = std::chrono::steady_clock::now();
                enemies.at(j).alreadyHit = true;
                enemies.at(j).inHitstun = true;
                enemies.at(j).hp -= playerProjectiles.at(i).power;

                if (enemies.at(j).hp <= 0)
                {
                    player.exp += enemies.at(j).xpGiven;
                    enemies.erase(enemies.begin() + j);
                }
                else
                {
                    double nanoseconds = (static_cast<double>(playerProjectiles.at(i).power) / static_cast<double>(enemies.at(j).maxHP)) * 333333333;
                    std::chrono::nanoseconds time = std::chrono::nanoseconds((static_cast<int>(nanoseconds)));
                    enemies.at(j).EnemyHitstunAnimation(time);
                }
                playerProjectiles.erase(playerProjectiles.begin() + i);
                i--;
                break;
            }
        }
        if (i != index) continue;
        playerProjectiles.at(i).xPosition += playerProjectiles.at(i).xVel * deltaSeconds;
        playerProjectiles.at(i).yPosition += playerProjectiles.at(i).yVel * deltaSeconds;
        if (playerProjectiles.at(i).xPosition >= rightBorder + (20 * scalerX)
            || playerProjectiles.at(i).xPosition <= leftBorder - (20 * scalerX)
            || playerProjectiles.at(i).yPosition >= 244 * scalerY
            || playerProjectiles.at(i).yPosition <= (-20 * scalerY)) {
            playerProjectiles.erase(playerProjectiles.begin() + i);
            i--;
            continue;
        }
    }
}

void UpdatePlayerLogic(double deltaSeconds) {
    double xDir, yDir;
    if (keys.c) {
        player.blocking = true;
        switch (player.facingDirection) {
        case 'u':
            player.frame = player_Blocking_U;
            break;
        case 'd':
            player.frame = player_Blocking_D;
            break;
        case 'l':
            player.frame = player_Blocking_L;
            break;
        case 'r':
            player.frame = player_Blocking_R;
            break;
        }
       
    }
    else if (keys.q || player.mAttking) {
        if (player.mAttking == false) {
            player.mAttking = true;
        }
        if (keys.q) {
            player.mAttkBegins = std::chrono::steady_clock::now();
            if ((std::chrono::steady_clock::now() - player.shotFireball >= player.mAttkSpeed) && player.MP >= 10) {
                player.shotFireball = std::chrono::steady_clock::now();
                int xV(0), yV(0);
                switch (player.facingDirection) {
                case 'u':
                    yV = -15;
                    break;
                case 'd':
                    yV = 15;
                    break;
                case 'l':
                    xV = -15;
                    break;
                case 'r':
                    xV = 15;
                    break;
                }
                playerProjectiles.emplace_back(fireball, player.xPosition, player.yPosition, xV, yV, 4, player.angleDegrees);
                player.MP -= 10;
            }
        }
        player.SwapMAttkFrames();
    }
    else if (keys.space == false && player.bAttkFrame == -1)
    {
        GetDirectionalInput(xDir, yDir, keys.right, keys.left, keys.down, keys.up);
        if ((xDir != 0 || yDir != 0)) {
            xDir *= 2.5;
            yDir *= 2.5;
            if (keys.lShift == true)
            {
                xDir *= 1.8;
                yDir *= 1.8;
                player.walkAnimationInterval = std::chrono::nanoseconds(142857142);
            }
            else
            {
                player.walkAnimationInterval = std::chrono::nanoseconds(200000000);
            }
            ApplyPlayerDirectionalInput(player, currentFrameTime, xDir * deltaSeconds, yDir * deltaSeconds);
        }
        else {
            player.PlayerIdle();
        }
    }
    else if ((keys.space == true && player.bAttkFrame == -1) || player.bAttkFrame != -1)
    {
        player.BasicAttack(enemies);
    }
    if (player.exp >= player.levelup) {
        player.mId = 9;
        player.PlayerLevelUpSequence();
    }
    if (player.iFrameActive) {
        if (std::chrono::steady_clock::now() - player.iFramesStart >= player.totaliFrames) {
            player.iFrameActive = false;
        }
        else if (std::chrono::steady_clock::now() - player.lastFlicker <= player.flickerTime) {
            player.frame = blank_Sprite;
        }
        else if (std::chrono::steady_clock::now() - player.lastFlicker >= player.flickerInterval) {
            player.lastFlicker = std::chrono::steady_clock::now();
        }
    }
    if (!keys.c) player.blocking = false;
}

void UpdateGameLogic(double deltaSeconds)  {
    if (gameState == 0) {
        if (!player.inLevelUpSequence) {
            if (std::chrono::steady_clock::now() - player.dmgLagStarted < player.dmgLagDur) return;
            player.UpdateHitBox();

            player.MP = min(player.maxMP, player.MP += (0.030 * deltaSeconds));

            // Env Logic
            for (auto door : environments.at(currentEnvID - 1).doors) {
                if (player.CheckCollision(door)) {
                    for (int i = 0; i < environments.at(currentEnvID - 1).enemyData.size(); i++) {
                        environments.at(currentEnvID - 1).enemyData[i].spawned = false;
                    }
                    enemies.clear();
                    enemies.shrink_to_fit();
                    if (door.destID == 19) {
                        gameState = 1;
                        return;
                    }
                    currentEnvID = door.destID;
                    if (!door.transferX) player.xPosition = door.destX;
                    if (!door.transferY) player.yPosition = door.destY;
                    continue;
                }
            }
            // Enemy Logic
            if (environments.at(currentEnvID - 1).enemyData.size() > 0) {
                for (int i = 0; i < environments.at(currentEnvID - 1).enemyData.size(); i++) {
                    if (environments.at(currentEnvID - 1).enemyData[i].deathStatus == false && environments.at(currentEnvID - 1).enemyData[i].spawned == false) {
                        float x = environments.at(currentEnvID - 1).enemyData[i].sPosX;
                        float y = environments.at(currentEnvID - 1).enemyData[i].sPosY;
                        enemies.emplace_back(environments.at(currentEnvID - 1).enemyData[i].enemyID, x * scalerX, y * scalerY);
                        std::uniform_int_distribution<int> movingOdds(false, true);
                        enemies.back().moving = movingOdds(generator);
                        std::uniform_real_distribution<float> interval(1.0, 3.0);
                        enemies.back().idleInterval = std::chrono::milliseconds(int(1000 * interval(generator)));
                        enemies.back().idlePoint = std::chrono::steady_clock::now();
                        environments.at(currentEnvID - 1).enemyData[i].spawned = true;
                    }
                }
            }
            for (int i = 0; i < enemies.size(); i++)
            {
                enemies.at(i).UpdateHitBox();
                if (enemies.at(i).CheckCollision(player) && !player.iFrameActive) {
                    player.iFrameActive = true;
                    player.iFramesStart = std::chrono::steady_clock::now();
                    player.lastFlicker = std::chrono::steady_clock::now();
                    float mod = 1;
                    if (player.blocking) mod = 0.25;
                    player.HP -= (10 * mod);

                }
                std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
                if (now - enemies.at(i).idlePoint >= enemies.at(i).idleInterval) {
                    enemies.at(i).idlePoint = std::chrono::steady_clock::now();
                    enemies.at(i).moving ^= true;
                }
                if (enemies.at(i).moving == false) {
                    enemies.at(i).frame = enemies.at(i).walkCycles[1];
                    continue;
                }
                if ((std::chrono::steady_clock::now() - enemies.at(i).hitStunStartTime) >= enemies.at(i).hitStunTime) {
                    if ((std::chrono::steady_clock::now() - enemies.at(i).timeSinceLastMovement) >= enemies.at(i).moveInterval) {
                        enemies.at(i).timeSinceLastMovement = std::chrono::steady_clock::now();
                        enemies.at(i).xDirection = (rand() % 100);
                        enemies.at(i).yDirection = (rand() % 100);
                        enemies.at(i).xDirection /= 100;
                        enemies.at(i).yDirection /= 100;
                        enemies.at(i).moveInterval = std::chrono::milliseconds(rand() % 1500);
                    }
                    ApplyEnemyDirectionalInput(enemies.at(i), 2 * enemies.at(i).xDirection * deltaSeconds, 2 * enemies.at(i).yDirection * deltaSeconds);
                }
                /*if ((std::chrono::steady_clock::now() - enemies.at(i).timeSinceLastMovement) >= std::chrono::seconds(5) && (std::chrono::steady_clock::now() - enemies.at(i).hitStunStartTime) >= enemies.at(i).hitStunTime)
                {
                    double leafXDir = ((rand() % 200)) - 100;
                    leafXDir /= 100;
                    double leafYDir = ((rand() % 200)) - 100;
                    leafYDir /= 100;
                    ApplyEnemyDirectionalInput(enemies.at(i), 2 * leafXDir * deltaSeconds, 2 * leafYDir * deltaSeconds);
                }
                else if ((std::chrono::steady_clock::now() - enemies.at(i).hitStunStartTime) >= enemies.at(i).hitStunTime)
                {
                    ApplyEnemyDirectionalInput(enemies.at(i), enemies.at(i).lastXDirection2 * deltaSeconds, enemies.at(i).lastYDirection2 * deltaSeconds);
                }*/
            }
            // Player Logic
            UpdatePlayerLogic(deltaSeconds);
            UpdateProjectileLogic(deltaSeconds);
            if (std::chrono::steady_clock::now() - lastMenuInput <= menInputBuffer) return;
            else if (keys.escape) {
                lastMenuInput = std::chrono::steady_clock::now();
                gameState = 1;
            }

        }
        else
        {
            HandleLevelUpSequence();
        }
    }
    else if (gameState == 1) pauseMen.UpdateLogic();
    else if (gameState == 2) saveMenu.UpdateLogic();
    else if (gameState == 3) equipMenu.UpdateLogic();
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{ 
    InitializeAssets();
    HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory);
    if (SUCCEEDED(hr))
    {

        WNDCLASSEX wc = { sizeof(WNDCLASSEX) };
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = WndProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = hInstance;
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = NULL;
        wc.lpszMenuName = NULL;
        wc.lpszClassName = L"Direct2DPNGWindow";
        wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

        if (RegisterClassEx(&wc))
        {
            HWND hWnd = CreateWindowEx(0, L"Direct2DPNGWindow", L"Direct2D PNG Example", WS_POPUP | WS_VISIBLE, 0, 0,
                sysScreenX, sysScreenY, NULL, NULL, hInstance, NULL);

            if (hWnd)
            {
                LoadMemory(hWnd, spriteData);
                ShowWindow(hWnd, nCmdShow);

                MSG msg;
                while (GetMessage(&msg, NULL, 0, 0))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }
        }

        pD2DFactory->Release();
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:
    {
        switch (wParam)
        {
        case VK_LEFT:
            keys.left = true;
            player.lastXDirection -= 1;
            break;
        case VK_RIGHT:
            keys.right = true;
            player.lastXDirection += 1;
            break;
        case VK_UP:
            keys.up = true;
            player.lastYDirection -= 1;
            break;
        case VK_DOWN:
            keys.down = true;
            player.lastYDirection += 1;
            break;
        case VK_SPACE:
            keys.space = true;
            break;
        case VK_SHIFT:
            keys.lShift = true;
            break;
        case VK_ESCAPE:
            keys.escape = true;
            break;
        case 0x51:
            keys.q = true;
            break;
        case 0x57:
            keys.w = true;
            break;
        case 0x45:
            keys.e = true;
            break;
        case 0x52:
            keys.r = true;
            break;
        case 0x41:
            keys.a = true;
            break;
        case 0x53:
            keys.s = true;
            break;
        case 0x44:
            keys.d = true;
            break;
        case 0x46:
            keys.f = true;
            break;
        case 0x43:
            keys.c = true;
            break;
        case VK_CONTROL:
            keys.ctrl = true;
            break;
        }
        InvalidateRect(hWnd, NULL, true);
        break;
    }
    case WM_KEYUP:
    {
        switch (wParam)
        {
        case VK_LEFT:
            keys.left = false;
            player.lastXDirection += 1;
            break;
        case VK_RIGHT:
            keys.right = false; 
            player.lastXDirection -= 1;
            break;
        case VK_UP:
            keys.up = false;
            player.lastYDirection += 1;
            break;
        case VK_DOWN:
            keys.down = false;
            player.lastYDirection -= 1;
            break;
        case VK_SPACE:
            keys.space = false;
            break;
        case VK_SHIFT:
            keys.lShift = false;
            break;
        case VK_ESCAPE:
            keys.escape = false;
            break;
        case 0x51:
            keys.q = false;
            break;
        case 0x57:
            keys.w = false;
            break;
        case 0x45:
            keys.e = false;
            break;
        case 0x52:
            keys.r = false;
            break;
        case 0x41:
            keys.a = false;
            break;
        case 0x53:
            keys.s = false;
            break;
        case 0x44:
            keys.d = false;
            break;
        case 0x46:
            keys.f = false;
            break;
        case 0x43:
            keys.c = false;
            break;
        case VK_CONTROL:
            keys.ctrl = false;
            break;
        }
        InvalidateRect(hWnd, NULL, true);
        break;
    }

    case WM_PAINT:
    case WM_DISPLAYCHANGE:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        std::chrono::duration<double> delta = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - timeSinceLogicUpdate);
        double deltaTime = delta.count() * 100;
        timeSinceLogicUpdate = std::chrono::steady_clock::now();
        UpdateGameLogic(deltaTime);

        Render(hWnd);

        EndPaint(hWnd, &ps);

        InvalidateRect(hWnd, NULL, FALSE);
    } break;

    case WM_DESTROY: {
        ReleaseMemory();
        PostQuitMessage(0);
    } break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}