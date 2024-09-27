#include <Windows.h>
#include <d2d1.h>
#include <wincodec.h>
#include <dwrite.h>
#include <chrono>
#include <vector>
#include <map>
#include <limits>
#include <time.h>
#include <stdlib.h>
#include <string>

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

// Weapon Sprites
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

// Environment
LPCWSTR testBackground = L"Sprites\\Environment\\testBackground.png";
LPCWSTR checkerBackground = L"Sprites\\Environment\\checkerBackground.png";

// UI
LPCWSTR hpBarShell = L"Sprites\\UI\\HPBar_Shell.png";
LPCWSTR hpBarFilling = L"Sprites\\UI\\HPBar_Filling.png";
LPCWSTR mpBarShell = L"Sprites\\UI\\MPBar_Shell.png";
LPCWSTR mpBarFilling = L"Sprites\\UI\\MPBar_Filling.png";
LPCWSTR expBarShell = L"Sprites\\UI\\EXPBar_Shell.png";
LPCWSTR expBarFilling = L"Sprites\\UI\\EXPBar_Filling.png";
LPCWSTR skillPanes = L"Sprites\\UI\\Skill Panes.png";
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



// Misc
LPCWSTR man = L"Sprites\\Enemies\\1.png";

// Maps of info regarding various enemies
std::map<const std::string, int> experience;

void populateEnemyExpList() {
    experience["Leafnir"] = 10;
}


// Interface: Starting point for Direct2D, used to create resources
ID2D1Factory* pD2DFactory = NULL;

// Object: Receives drawing commands
ID2D1HwndRenderTarget* pRenderTarget = NULL;

// Map of Direct2D Bitmaps
std::map<LPCWSTR, ID2D1Bitmap*> pBitmaps;

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
    std::string lastKeyPressed;
} keys;




void GetDirectionalInput(double& xDirection, double& yDirection, bool keyRight, bool keyLeft, bool keyDown, bool keyUp)
{
    xDirection = (keyRight ? 1 : 0) - (keyLeft ? 1 : 0);
    yDirection = (keyDown ? 1 : 0) - (keyUp ? 1 : 0);
}

// Essentially represents anything that can appear on screen
class Object
{
public:
    double xPosition = sysScreenX / 2;
    double yPosition = sysScreenY / 2;
    LPCWSTR fileName = nullptr;
    LPCWSTR lastfilepath = nullptr;
    LPCWSTR secondlastfilepath = nullptr;
    double lastXDirection = 0;
    double lastYDirection = 0;
    std::chrono::steady_clock::time_point lastWalkTime = std::chrono::steady_clock::now();
    int framesWalked2 = 0;
    bool fileNameChanged = false;
    int state = 3;
    int count = 0;
    D2D1_RECT_F hurtbox;

    double lastXDirection2 = 0;
    double lastYDirection2 = 0;

    void WriteFileName(LPCWSTR file_Name)
    {
        fileName = file_Name;
        fileNameChanged = true;
    }

    void DestroyObject()
    {
        fileName = nullptr;
        fileNameChanged = true;
    }
};

// Objects but as enemies
class Enemy : public Object
{
public:

    std::string name;
    int hp = 10;
    int maxHP = 10;
    bool damageTaken = false;
    bool alreadyHit = false;
    bool inHitstun = false;
    std::chrono::nanoseconds hitStunTime;
    std::chrono::steady_clock::time_point hitStunStartTime = std::chrono::steady_clock::now();

    Enemy()
    {
        xPosition = rand() % 1920;
        yPosition = rand() % 1080;
        fileName = leafEnemyStationary;
        lastfilepath = leafEnemyStationary;
        secondlastfilepath = leafEnemyDownWalkingRight;
        fileNameChanged = true;
        SetEnemyHurtBox();
    }

    void SetEnemyHurtBox()
    {
        // Get the bitmap for the currently loaded file
        ID2D1Bitmap* pBitmap = pBitmaps[fileName];
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
        if (std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - lastWalkTime) >= std::chrono::nanoseconds(166666666))
        {
            if (lastfilepath == leafEnemyDownWalkingLeft && secondlastfilepath == leafEnemyStationary)
            {
                fileName = leafEnemyStationary;
                lastfilepath = fileName;
                secondlastfilepath = leafEnemyDownWalkingLeft;
            }
            else if (lastfilepath == leafEnemyStationary && secondlastfilepath == leafEnemyDownWalkingLeft)
            {
                fileName = leafEnemyDownWalkingRight;
                lastfilepath = fileName;
                secondlastfilepath = leafEnemyStationary;
            }
            else if (lastfilepath == leafEnemyDownWalkingRight && secondlastfilepath == leafEnemyStationary)
            {
                fileName = leafEnemyStationary;
                lastfilepath = fileName;
                secondlastfilepath = leafEnemyDownWalkingRight;
            }
            else if (lastfilepath == leafEnemyStationary && secondlastfilepath == leafEnemyDownWalkingRight)
            {
                fileName = leafEnemyDownWalkingLeft;
                lastfilepath = fileName;
                secondlastfilepath = leafEnemyStationary;
            }
            else 
            {
                fileName = leafEnemyDownWalkingRight;
                lastfilepath = fileName;
                secondlastfilepath = leafEnemyStationary;
            }
            lastWalkTime = std::chrono::steady_clock::now();
            fileNameChanged = true;
        }
    }

    void EnemyHitstunAnimation(std::chrono::nanoseconds time)
    {
        fileName = leafEnemyDownHitstun;
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
    int strength = 11;
    int dexterity = 2;
    int intelligence = 1;
    int wisdom = 12;
    int defense = 23;
    int magicDefense = 111;
    int trueDefense = 121;
    int agility = 122;
    int luck = 999;

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
    std::chrono::nanoseconds basicAttackFrameIncrements = std::chrono::nanoseconds(16666666);
    std::chrono::nanoseconds basicAttackStartLag = std::chrono::nanoseconds(66666666);
    std::chrono::nanoseconds basicAttackEndLag = std::chrono::nanoseconds(133333333);
    std::chrono::nanoseconds hitLag = std::chrono::nanoseconds(0);
    std::chrono::nanoseconds walkAnimationInterval = std::chrono::nanoseconds(166666666); 
    std::chrono::steady_clock::time_point lastLevelUpOverworldTextTime;

    
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

    Player()
    {
        fileName = playerStationaryDown;
        fileNameChanged = true;
        SetPlayerHurtBox();
    }

    void PlayerIdle()
    {
        secondlastfilepath = nullptr;
        if (lastfilepath == playerWalkingDownLeft || lastfilepath == playerStationaryDown || lastfilepath == playerWalkingDownRight)
        {
            fileName = playerStationaryDown;
        }
        else if (lastfilepath == playerWalkingUpLeft || lastfilepath == playerStationaryUp || lastfilepath == playerWalkingUpRight)
        {
            fileName = playerStationaryUp;
        }
        else if (lastfilepath == playerWalkingLeftLeft || lastfilepath == playerStationaryLeft || lastfilepath == playerWalkingLeftRight)
        {
            fileName = playerStationaryLeft;
        }
        else if (lastfilepath == playerWalkingRightLeft || lastfilepath == playerStationaryRight || lastfilepath == playerWalkingRightRight)
        {
            fileName = playerStationaryRight;
        }
        lastXDirection = 0;
        lastYDirection = 0;
        lastfilepath = fileName;
        fileNameChanged = true;
        SetPlayerHurtBox();
    }

    // These functions are designed to condense the walking logic and make the PlayerWalkAnimation function more readable
    void PlayerWalkingDownLogic(double xDirection, double yDirection)
    {
        if (lastfilepath != playerStationaryDown && lastfilepath != playerWalkingDownLeft && lastfilepath != playerWalkingDownRight)
        {
            fileName = playerWalkingDownLeft;
            lastfilepath = fileName;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerStationaryDown && secondlastfilepath == nullptr)
        {
            fileName = playerWalkingDownLeft;
            lastfilepath = fileName;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerWalkingDownLeft && secondlastfilepath == nullptr)
        {
            fileName = playerStationaryDown;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerStationaryDown && secondlastfilepath == playerWalkingDownLeft)
        {
            fileName = playerWalkingDownRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerWalkingDownRight && secondlastfilepath == playerStationaryDown)
        {
            fileName = playerStationaryDown;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerStationaryDown && secondlastfilepath == playerWalkingDownRight)
        {
            fileName = playerWalkingDownLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerWalkingDownLeft && secondlastfilepath == playerStationaryDown)
        {
            fileName = playerStationaryDown;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        lastXDirection = xDirection;
        lastYDirection = yDirection;
    }
    void PlayerWalkingUpLogic(double xDirection, double yDirection)
    {
        if (lastfilepath != playerStationaryUp && lastfilepath != playerWalkingUpLeft && lastfilepath != playerWalkingUpRight)
        {
            fileName = playerWalkingUpLeft;
            lastfilepath = fileName;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerStationaryUp && secondlastfilepath == nullptr)
        {
            fileName = playerWalkingUpLeft;
            lastfilepath = fileName;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerWalkingUpLeft && secondlastfilepath == nullptr)
        {
            fileName = playerStationaryUp;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerStationaryUp && secondlastfilepath == playerWalkingUpLeft)
        {
            fileName = playerWalkingUpRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerWalkingUpRight && secondlastfilepath == playerStationaryUp)
        {
            fileName = playerStationaryUp;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerStationaryUp && secondlastfilepath == playerWalkingUpRight)
        {
            fileName = playerWalkingUpLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerWalkingUpLeft && secondlastfilepath == playerStationaryUp)
        {
            fileName = playerStationaryUp;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        lastXDirection = xDirection;
        lastYDirection = yDirection;
    }
    void PlayerWalkingLeftLogic(double xDirection, double yDirection)
    {
        if (lastfilepath != playerStationaryLeft && lastfilepath != playerWalkingLeftLeft && lastfilepath != playerWalkingLeftRight)
        {
            fileName = playerWalkingLeftLeft;
            lastfilepath = fileName;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerStationaryLeft && secondlastfilepath == nullptr)
        {
            fileName = playerWalkingLeftLeft;
            lastfilepath = fileName;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerWalkingLeftLeft && secondlastfilepath == nullptr)
        {
            fileName = playerStationaryLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerStationaryLeft && secondlastfilepath == playerWalkingLeftLeft)
        {
            fileName = playerWalkingLeftRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerWalkingLeftRight && secondlastfilepath == playerStationaryLeft)
        {
            fileName = playerStationaryLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerStationaryLeft && secondlastfilepath == playerWalkingLeftRight)
        {
            fileName = playerWalkingLeftLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerWalkingLeftLeft && secondlastfilepath == playerStationaryLeft)
        {
            fileName = playerStationaryLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        lastXDirection = xDirection;
        lastYDirection = yDirection;
    }
    void PlayerWalkingRightLogic(double xDirection, double yDirection)
    {
        if (lastfilepath != playerStationaryRight && lastfilepath != playerWalkingRightLeft && lastfilepath != playerWalkingRightRight)
        {
            fileName = playerWalkingRightLeft;
            lastfilepath = fileName;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerStationaryRight && secondlastfilepath == nullptr)
        {
            fileName = playerWalkingRightLeft;
            lastfilepath = fileName;
            secondlastfilepath = nullptr;
        }
        else if (lastfilepath == playerWalkingRightLeft && secondlastfilepath == nullptr)
        {
            fileName = playerStationaryRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerStationaryRight && secondlastfilepath == playerWalkingRightLeft)
        {
            fileName = playerWalkingRightRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerWalkingRightRight && secondlastfilepath == playerStationaryRight)
        {
            fileName = playerStationaryRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerStationaryRight && secondlastfilepath == playerWalkingRightRight)
        {
            fileName = playerWalkingRightLeft;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        else if (lastfilepath == playerWalkingRightLeft && secondlastfilepath == playerStationaryRight)
        {
            fileName = playerStationaryRight;
            secondlastfilepath = lastfilepath;
            lastfilepath = fileName;
        }
        lastXDirection = xDirection;
        lastYDirection = yDirection;
    }

    void PlayerWalkAnimation(double xDirection, double yDirection)
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
            fileNameChanged = true;
        }
    }

    // Sets the hurtbox for the player. This is how the game knows if the player has been hit or is touching something.
    void SetPlayerHurtBox()
    {
        ID2D1Bitmap* pBitmap = pBitmaps[fileName];
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

    void SwapAttackFrames(LPCWSTR nextFrame, LPCWSTR lastFrame, LPCWSTR weaponFrame) {
        fileName = nextFrame;
        lastfilepath = fileName;
        secondlastfilepath = lastFrame;
        fileNameChanged = true;
        weaponFileName = weaponFrame;
    }

    void BasicAttack(std::vector<Enemy>& enemies)
    {
        if (lastfilepath == playerStationaryUp || lastfilepath == playerWalkingUpLeft || lastfilepath == playerWalkingUpRight)
        {
            SwapAttackFrames(playerStationaryUpBasicAttack0, playerStationaryUp, testSwordBasicAttackUp0);
            ID2D1Bitmap* pBitmap = pBitmaps[fileName];
            if (pBitmap)
            {
                D2D1_SIZE_F size = pBitmap->GetSize();
                weaponXPosition = xPosition + ((size.width * 10 / 13) * scalerX);
                weaponYPosition = yPosition + ((size.height * 13 / 21) * scalerY);
            }

            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            isBasicAttacking = true;
            hitLag = std::chrono::nanoseconds(0);

        }
        else if (lastfilepath == playerStationaryUpBasicAttack0
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= (hitLag + basicAttackFrameIncrements))
        {
            SwapAttackFrames(playerStationaryUpBasicAttack1, playerStationaryUpBasicAttack0, testSwordBasicAttackUp1);
            ID2D1Bitmap* pBitmap = pBitmaps[fileName];
            if (pBitmap)
            {
                D2D1_SIZE_F size = pBitmap->GetSize();
                weaponXPosition = xPosition + ((size.width * 12 / 13) * scalerX);
                weaponYPosition = yPosition + ((size.height * 11 / 21) * scalerY);
            }

            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            hitLag = std::chrono::nanoseconds(0);
        }
        else if (lastfilepath == playerStationaryUpBasicAttack1
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= (hitLag + basicAttackFrameIncrements))
        {
            SwapAttackFrames(playerStationaryUpBasicAttack2, playerStationaryUpBasicAttack1, testSwordBasicAttackUp2);
            ID2D1Bitmap* pBitmap = pBitmaps[fileName];
            if (pBitmap)
            {
                D2D1_SIZE_F size = pBitmap->GetSize();
                weaponXPosition = xPosition + ((size.width * 12 / 13) * scalerX);
                weaponYPosition = yPosition;
            }

            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
        }
        else if (lastfilepath == playerStationaryUpBasicAttack2
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + basicAttackFrameIncrements)
        {
            refreshTimes.emplace_back(std::chrono::steady_clock::now() - lastBasicAttackFrame);
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            SwapAttackFrames(playerStationaryUpBasicAttack3, playerStationaryUpBasicAttack2, testSwordBasicAttackUp3);

            ID2D1Bitmap* pBitmap = pBitmaps[fileName];
            if (pBitmap)
            {
                D2D1_SIZE_F size = pBitmap->GetSize();
                weaponXPosition = xPosition + ((size.width * 11 / 13) * scalerX);
                weaponYPosition = yPosition - ((size.height * 10 / 21) * scalerY);
            }
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
        }
        else if (lastfilepath == playerStationaryUpBasicAttack3
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + basicAttackFrameIncrements)
        {
            refreshTimes.emplace_back(std::chrono::steady_clock::now() - lastBasicAttackFrame);
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            SwapAttackFrames(playerStationaryUpBasicAttack4, playerStationaryUpBasicAttack3, testSwordBasicAttackUp4);

            ID2D1Bitmap* pBitmap = pBitmaps[fileName];
            if (pBitmap)
            {
                D2D1_SIZE_F size = pBitmap->GetSize();
                weaponXPosition = xPosition + ((size.width * 5 / 13) * scalerX);
                weaponYPosition = yPosition - ((size.height * 13 / 21) * scalerY);
            }
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
        }
        else if (lastfilepath == playerStationaryUpBasicAttack4
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + basicAttackFrameIncrements)
        {
            refreshTimes.emplace_back(std::chrono::steady_clock::now() - lastBasicAttackFrame);
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            SwapAttackFrames(playerStationaryUpBasicAttack5, playerStationaryUpBasicAttack4, testSwordBasicAttackUp5);

            ID2D1Bitmap* pBitmap = pBitmaps[fileName];
            if (pBitmap)
            {
                D2D1_SIZE_F size = pBitmap->GetSize();
                weaponXPosition = xPosition - ((size.width * 6 / 13) * scalerX);
                weaponYPosition = yPosition - ((size.height * 10 / 21) * scalerY);
            }
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
        }
        else if (lastfilepath == playerStationaryUpBasicAttack5
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + basicAttackFrameIncrements)
        {
            refreshTimes.emplace_back(std::chrono::steady_clock::now() - lastBasicAttackFrame);
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            SwapAttackFrames(playerStationaryUpBasicAttack6, playerStationaryUpBasicAttack5, testSwordBasicAttackUp6);

            ID2D1Bitmap* pBitmap = pBitmaps[fileName];
            if (pBitmap)
            {
                D2D1_SIZE_F size = pBitmap->GetSize();
                weaponXPosition = xPosition - ((size.width * 15 / 13) * scalerX);
                weaponYPosition = yPosition - ((size.height * 6 / 21) * scalerY);
            }
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
        }
        else if (lastfilepath == playerStationaryUpBasicAttack6
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + (basicAttackFrameIncrements))
        {
            refreshTimes.emplace_back(std::chrono::steady_clock::now() - lastBasicAttackFrame);
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            SwapAttackFrames(playerStationaryUpBasicAttack7, playerStationaryUpBasicAttack6, testSwordBasicAttackUp7);

            ID2D1Bitmap* pBitmap = pBitmaps[fileName];
            if (pBitmap)
            {
                D2D1_SIZE_F size = pBitmap->GetSize();
                weaponXPosition = xPosition - ((size.width * 18 / 13) * scalerX);
                weaponYPosition = yPosition + ((size.height * 1 / 21) * scalerY);
            }
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
        }
        else if (lastfilepath == playerStationaryUpBasicAttack7
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + (basicAttackFrameIncrements))
            {
                refreshTimes.emplace_back(std::chrono::steady_clock::now() - lastBasicAttackFrame);
                lastBasicAttackFrame = std::chrono::steady_clock::now();
                SwapAttackFrames(playerStationaryUpBasicAttack8, playerStationaryUpBasicAttack7, testSwordBasicAttackUp8);

                ID2D1Bitmap* pBitmap = pBitmaps[fileName];
                if (pBitmap)
                {
                    D2D1_SIZE_F size = pBitmap->GetSize();
                    weaponXPosition = xPosition - ((size.width * 15 / 13) * scalerX);
                    weaponYPosition = yPosition + ((size.height * 13 / 21) * scalerY);
                }
                SetHitBox();
                SetPlayerHurtBox();
                basicAttackFrameThresholds += 1;
             }
        else if (lastfilepath == playerStationaryUpBasicAttack8
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= basicAttackEndLag + (hitLag + (basicAttackFrameIncrements * 3))
            && keys.space == false)
        {
            fileName = playerStationaryUp;
            lastfilepath = fileName;
            secondlastfilepath = nullptr;
            fileNameChanged = true;
            isBasicAttacking = false;

            weaponFileName = nullptr;
            RemoveHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds = 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            for (int i = 0; i < enemies.size(); i++)
            {
                enemies.at(i).alreadyHit = false;
            }
        }
        /*if (lastfilepath != playerStationaryUp)
        {
            framesBasicAttacked++;
        }*/
        if (lastfilepath == playerStationaryDown || lastfilepath == playerWalkingDownLeft || lastfilepath == playerWalkingDownRight
            || lastfilepath == playerStationaryLeft || lastfilepath == playerWalkingLeftLeft || lastfilepath == playerWalkingLeftRight
            || lastfilepath == playerStationaryRight || lastfilepath == playerWalkingRightLeft || lastfilepath == playerWalkingRightRight)
        {
            isBasicAttacking = false;
        }

        if (isBasicAttacking)
        {
            for (int i = 0; i < enemies.size(); i++)
            {
                if (enemies.at(i).alreadyHit == false)
                {
                    if (hitbox.right >= enemies.at(i).hurtbox.left && hitbox.left <= enemies.at(i).hurtbox.right
                        && hitbox.top <= enemies.at(i).hurtbox.bottom && hitbox.bottom >= enemies.at(i).hurtbox.top)
                    {
                        /*enemies.at(i).damageTaken = true;*/
                        enemies.at(i).alreadyHit = true;
                        enemies.at(i).inHitstun = true;
                        enemies.at(i).hp -= 10;
                        /*double nanoseconds = (static_cast<double>(attack) / static_cast<double>(enemies.at(i).maxHP)) * 333333333;
                        hitLag = std::chrono::nanoseconds((static_cast<int>(nanoseconds)));*/

                        if (enemies.at(i).hp <= 0)
                        {
                            exp += 100;
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
        ID2D1Bitmap* pBitmap = pBitmaps[weaponFileName];
        if (pBitmap)
        {
            D2D1_SIZE_F size = pBitmap->GetSize();
            hitbox = D2D1::RectF(weaponXPosition, weaponYPosition,
                (size.width * scalerX) + weaponXPosition, (size.height * scalerY) + weaponYPosition);
        }
    }

    void RemoveHitBox()
    {
        hitbox.right = hitbox.left = hitbox.top = hitbox.bottom = -1;
    }

    void PlayerLevelUpSequence() {
        inLevelUpSequence = true;
        inLevelUpFanfare = true;
        fileName = playerLevelUp;
        weaponFileName = nullptr;
        yPosition -= 15 * scalerY;
        RemoveHitBox();
        levelUpFanfareBegin = std::chrono::steady_clock::now();
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
            player.PlayerWalkAnimation(xDir, yDir);
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

// Images must be loaded into a container before images can be loaded and swapped onto the screen.
// I don't yet know why, but sprites will not appear on screen unless this is used
void StoreSpriteFileNames(std::vector<LPCWSTR>& spriteData)
{
    //---------------- Player Sprites -----------------//
    
    //down stand and move
    spriteData.emplace_back(playerStationaryDown);
    spriteData.emplace_back(playerWalkingDownLeft);
    spriteData.emplace_back(playerWalkingDownRight);

    // up stand and move
    spriteData.emplace_back(playerStationaryUp);
    spriteData.emplace_back(playerWalkingUpLeft);
    spriteData.emplace_back(playerWalkingUpRight);

    // left stand and mnove
    spriteData.emplace_back(playerStationaryLeft);
    spriteData.emplace_back(playerWalkingLeftLeft);
    spriteData.emplace_back(playerWalkingLeftRight);

    // right stand and move
    spriteData.emplace_back(playerStationaryRight);
    spriteData.emplace_back(playerWalkingRightLeft);
    spriteData.emplace_back(playerWalkingRightRight);

    // player hurtbox
    spriteData.emplace_back(playerHurtBox);

    // player basic attack animation
    spriteData.emplace_back(playerStationaryUpBasicAttack0);
    spriteData.emplace_back(playerStationaryUpBasicAttack1);
    spriteData.emplace_back(playerStationaryUpBasicAttack2);
    spriteData.emplace_back(playerStationaryUpBasicAttack3);
    spriteData.emplace_back(playerStationaryUpBasicAttack4);
    spriteData.emplace_back(playerStationaryUpBasicAttack5);
    spriteData.emplace_back(playerStationaryUpBasicAttack6);
    spriteData.emplace_back(playerStationaryUpBasicAttack7);
    spriteData.emplace_back(playerStationaryUpBasicAttack8);

    // player weapon animations
    spriteData.emplace_back(testSwordBasicAttackUp0);
    spriteData.emplace_back(testSwordBasicAttackUp1);
    spriteData.emplace_back(testSwordBasicAttackUp2);
    spriteData.emplace_back(testSwordBasicAttackUp3);
    spriteData.emplace_back(testSwordBasicAttackUp4);
    spriteData.emplace_back(testSwordBasicAttackUp5);
    spriteData.emplace_back(testSwordBasicAttackUp6);
    spriteData.emplace_back(testSwordBasicAttackUp7);
    spriteData.emplace_back(testSwordBasicAttackUp8);

    // Player level up pose
    spriteData.emplace_back(playerLevelUp);


    
    //---------------- Enemies -----------------//

    // Leaf Enemy
    spriteData.emplace_back(leafEnemyStationary);
    spriteData.emplace_back(leafEnemyDownWalkingLeft);
    spriteData.emplace_back(leafEnemyDownWalkingRight);
    spriteData.emplace_back(leafEnemyDownHitstun);



    //---------------- UI -----------------//

    // player hitbox
    spriteData.emplace_back(playerHitBox);

    // HP Bar
    spriteData.emplace_back(hpBarShell);
    spriteData.emplace_back(hpBarFilling);

    // MP Bar
    spriteData.emplace_back(mpBarShell);
    spriteData.emplace_back(mpBarFilling);

    // MP Bar
    spriteData.emplace_back(expBarShell);
    spriteData.emplace_back(expBarFilling);

    // Level Up
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

    // Status Numbers
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


    //---------------- Environment -----------------//

    // Background
    spriteData.emplace_back(testBackground);
    spriteData.emplace_back(checkerBackground);
}

void CreateDeviceResources(HWND hWnd, std::vector<LPCWSTR> spriteData)
{
    HRESULT hr = S_OK;

    if (!pRenderTarget)
    {
        RECT rc;
        GetClientRect(hWnd, &rc);

        D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

        hr = pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hWnd, size), &pRenderTarget);
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
            return;
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
        hr = pRenderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, &pBitmap);

        if (SUCCEEDED(hr))
        {
            j++;
            pBitmaps[spriteData.at(i)] = pBitmap;
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
        hr = pRenderTarget->CreateSolidColorBrush(
            D2D1::ColorF(D2D1::ColorF::White),
            &pBrush
        );
    }
}

void DiscardDeviceResources()
{
    if (pBrush)
    {
        pBrush->Release();
        pBrush = NULL;
    }

    if (pRenderTarget)
    {
        pRenderTarget->Release();
        pRenderTarget = NULL;
    }
    for (auto& pair : pBitmaps)
    {
        ID2D1Bitmap* pBitmap = pair.second;
        if (pBitmap)
        {
            pBitmap->Release();
        }
    }
    pBitmaps.clear();
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

void TranslateStatstoBitmap(int stat, ID2D1Bitmap*& bitmap1, ID2D1Bitmap*& bitmap2, ID2D1Bitmap*& bitmap3, bool selected) {
    std::string statString = std::to_string(stat);


    if (!selected) 
    {
        switch (statString[0])
        {
        case '0':
            bitmap1 = pBitmaps[Stat_Number_0];
            break;
        case '1':
            bitmap1 = pBitmaps[Stat_Number_1];
            break;
        case '2':
            bitmap1 = pBitmaps[Stat_Number_2];
            break;
        case '3':
            bitmap1 = pBitmaps[Stat_Number_3];
            break;
        case '4':
            bitmap1 = pBitmaps[Stat_Number_4];
            break;
        case '5':
            bitmap1 = pBitmaps[Stat_Number_5];
            break;
        case '6':
            bitmap1 = pBitmaps[Stat_Number_6];
            break;
        case '7':
            bitmap1 = pBitmaps[Stat_Number_7];
            break;
        case '8':
            bitmap1 = pBitmaps[Stat_Number_8];
            break;
        case '9':
            bitmap1 = pBitmaps[Stat_Number_9];
            break;
        }

        if (stat >= 10) {
            switch (statString[1])
            {
            case '0':
                bitmap2 = pBitmaps[Stat_Number_0];
                break;
            case '1':
                bitmap2 = pBitmaps[Stat_Number_1];
                break;
            case '2':
                bitmap2 = pBitmaps[Stat_Number_2];
                break;
            case '3':
                bitmap2 = pBitmaps[Stat_Number_3];
                break;
            case '4':
                bitmap2 = pBitmaps[Stat_Number_4];
                break;
            case '5':
                bitmap2 = pBitmaps[Stat_Number_5];
                break;
            case '6':
                bitmap2 = pBitmaps[Stat_Number_6];
                break;
            case '7':
                bitmap2 = pBitmaps[Stat_Number_7];
                break;
            case '8':
                bitmap2 = pBitmaps[Stat_Number_8];
                break;
            case '9':
                bitmap2 = pBitmaps[Stat_Number_9];
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
                bitmap3 = pBitmaps[Stat_Number_0];
                break;
            case '1':
                bitmap3 = pBitmaps[Stat_Number_1];
                break;
            case '2':
                bitmap3 = pBitmaps[Stat_Number_2];
                break;
            case '3':
                bitmap3 = pBitmaps[Stat_Number_3];
                break;
            case '4':
                bitmap3 = pBitmaps[Stat_Number_4];
                break;
            case '5':
                bitmap3 = pBitmaps[Stat_Number_5];
                break;
            case '6':
                bitmap3 = pBitmaps[Stat_Number_6];
                break;
            case '7':
                bitmap3 = pBitmaps[Stat_Number_7];
                break;
            case '8':
                bitmap3 = pBitmaps[Stat_Number_8];
                break;
            case '9':
                bitmap3 = pBitmaps[Stat_Number_9];
                break;
            }
        }
        else {
            bitmap3 = nullptr;
        }
    }

    else
    {
        switch (statString[0])
        {
        case '0':
            bitmap1 = pBitmaps[Yellow_Stat_Number_0];
            break;
        case '1':
            bitmap1 = pBitmaps[Yellow_Stat_Number_1];
            break;
        case '2':
            bitmap1 = pBitmaps[Yellow_Stat_Number_2];
            break;
        case '3':
            bitmap1 = pBitmaps[Yellow_Stat_Number_3];
            break;
        case '4':
            bitmap1 = pBitmaps[Yellow_Stat_Number_4];
            break;
        case '5':
            bitmap1 = pBitmaps[Yellow_Stat_Number_5];
            break;
        case '6':
            bitmap1 = pBitmaps[Yellow_Stat_Number_6];
            break;
        case '7':
            bitmap1 = pBitmaps[Yellow_Stat_Number_7];
            break;
        case '8':
            bitmap1 = pBitmaps[Yellow_Stat_Number_8];
            break;
        case '9':
            bitmap1 = pBitmaps[Yellow_Stat_Number_9];
            break;
        }

        if (stat >= 10) {
            switch (statString[1])
            {
            case '0':
                bitmap2 = pBitmaps[Yellow_Stat_Number_0];
                break;
            case '1':
                bitmap2 = pBitmaps[Yellow_Stat_Number_1];
                break;
            case '2':
                bitmap2 = pBitmaps[Yellow_Stat_Number_2];
                break;
            case '3':
                bitmap2 = pBitmaps[Yellow_Stat_Number_3];
                break;
            case '4':
                bitmap2 = pBitmaps[Yellow_Stat_Number_4];
                break;
            case '5':
                bitmap2 = pBitmaps[Yellow_Stat_Number_5];
                break;
            case '6':
                bitmap2 = pBitmaps[Yellow_Stat_Number_6];
                break;
            case '7':
                bitmap2 = pBitmaps[Yellow_Stat_Number_7];
                break;
            case '8':
                bitmap2 = pBitmaps[Yellow_Stat_Number_8];
                break;
            case '9':
                bitmap2 = pBitmaps[Yellow_Stat_Number_9];
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
                bitmap3 = pBitmaps[Yellow_Stat_Number_0];
                break;
            case '1':
                bitmap3 = pBitmaps[Yellow_Stat_Number_1];
                break;
            case '2':
                bitmap3 = pBitmaps[Yellow_Stat_Number_2];
                break;
            case '3':
                bitmap3 = pBitmaps[Yellow_Stat_Number_3];
                break;
            case '4':
                bitmap3 = pBitmaps[Yellow_Stat_Number_4];
                break;
            case '5':
                bitmap3 = pBitmaps[Yellow_Stat_Number_5];
                break;
            case '6':
                bitmap3 = pBitmaps[Yellow_Stat_Number_6];
                break;
            case '7':
                bitmap3 = pBitmaps[Yellow_Stat_Number_7];
                break;
            case '8':
                bitmap3 = pBitmaps[Yellow_Stat_Number_8];
                break;
            case '9':
                bitmap3 = pBitmaps[Yellow_Stat_Number_9];
                break;
            }
        }
        else {
            bitmap3 = nullptr;
        }
    }
}

void RenderStats(ID2D1Bitmap* stat1, ID2D1Bitmap* stat2, ID2D1Bitmap* stat3, int yOffset) {
    int xOffset1, xOffset2, xOffset3;

    if (stat1 && stat2 && stat3) 
    {
        D2D1_SIZE_F size1 = stat1->GetSize();
        D2D1_SIZE_F size2 = stat2->GetSize();
        D2D1_SIZE_F size3 = stat3->GetSize();
        xOffset1 = 171 - size1.width - size2.width - size3.width;
        xOffset2 = 172 - size2.width - size3.width;
        xOffset3 = 173 - size3.width;
    } 
    else if (stat1 && stat2) 
    {
        D2D1_SIZE_F size1 = stat1->GetSize();
        D2D1_SIZE_F size2 = stat2->GetSize();
        xOffset1 = 172 - size1.width - size2.width;
        xOffset2 = 173 - size2.width;
    } 
    else if (stat1) // if statement not necessary, but could prevent errors if stat were to somehow be emptied
    {
        D2D1_SIZE_F size1 = stat1->GetSize();
        xOffset1 = 173 - size1.width;
    }

    if (stat1)
    {
        D2D1_SIZE_F size1 = stat1->GetSize();
        D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (xOffset1 * scalerX), yOffset * scalerY,
            (leftBorder + ((xOffset1 + size1.width) * scalerX)), ((size1.height + yOffset) * scalerY));
        pRenderTarget->DrawBitmap(stat1, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

        if (stat2)
        {
            D2D1_SIZE_F size2 = stat2->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (xOffset2 * scalerX), yOffset * scalerY,
                (leftBorder + ((xOffset2 + size2.width) * scalerX)), ((size2.height + yOffset) * scalerY));
            pRenderTarget->DrawBitmap(stat2, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

            if (stat3)
            {
                D2D1_SIZE_F size3 = stat3->GetSize();
                D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (xOffset3 * scalerX), yOffset * scalerY,
                    (leftBorder + ((xOffset3 + size3.width) * scalerX)), ((size3.height + yOffset) * scalerY));
                pRenderTarget->DrawBitmap(stat3, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
            }
        }
    }
}


void Render(HWND hWnd, std::vector<LPCWSTR> spriteData, Player& player, std::vector<Enemy> enemies)
{
    if (!pRenderTarget)
    {
        CreateDeviceResources(hWnd, spriteData);
    }

    if (pRenderTarget)
    {
        pRenderTarget->BeginDraw();

        pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Black));

        // Get bitmap for background
        ID2D1Bitmap* background = pBitmaps[testBackground];

        // Render background
        if (background)
        {
            D2D1_RECT_F destRect = D2D1::RectF(leftBorder, 0, rightBorder,
                224 * scalerY);
            pRenderTarget->DrawBitmap(background, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

        }

        // Enemies
        for (int i = 0; i < enemies.size(); i++)
        {
            // Get bitmap for enemies
            ID2D1Bitmap* enemyFrameBitmap = pBitmaps[enemies.at(i).fileName];

            // Render player
            if (enemyFrameBitmap)
            {
                D2D1_SIZE_F size = enemyFrameBitmap->GetSize();
                D2D1_RECT_F destRect = D2D1::RectF(enemies.at(i).xPosition, enemies.at(i).yPosition,
                    (size.width * scalerX) + enemies.at(i).xPosition, (size.height * scalerY) + enemies.at(i).yPosition);
                pRenderTarget->DrawBitmap(enemyFrameBitmap, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
            }

            LPCWSTR file_Name;
            if (enemies.at(i).damageTaken)
            {
                file_Name = playerHitBox;
            }
            else
            {
                file_Name = playerHurtBox;
            }

            //ID2D1Bitmap* enemyHurtBoxBitmap = pBitmaps[file_Name];

            //// Draw the hurtboxbitmap
            //if (enemyHurtBoxBitmap)
            //{
            //    D2D1_SIZE_F size;
            //    size.width = enemies.at(i).hurtbox.right - enemies.at(i).hurtbox.left;
            //    size.height = enemies.at(i).hurtbox.bottom - enemies.at(i).hurtbox.top;
            //    D2D1_RECT_F destRect = D2D1::RectF(enemies.at(i).hurtbox.left, enemies.at(i).hurtbox.top,
            //        size.width + enemies.at(i).hurtbox.left, size.height + enemies.at(i).hurtbox.top);
            //    pRenderTarget->DrawBitmap(enemyHurtBoxBitmap, destRect);
            //}
        }

        // Get the player bitmap
        ID2D1Bitmap* playerFrameBitmap = pBitmaps[player.fileName];

        // Render player
        if (playerFrameBitmap)
        {
            D2D1_SIZE_F size = playerFrameBitmap->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(player.xPosition, player.yPosition,
                (size.width * scalerX) + player.xPosition, (size.height * scalerY) + player.yPosition);
            pRenderTarget->DrawBitmap(playerFrameBitmap, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
        }

        //// Get hurtbox bitmap
        //ID2D1Bitmap* playerHurtBoxBitmap = pBitmaps[playerHurtBox];

        //// Render hurtbox
        //if (playerHurtBoxBitmap)
        //{
        //    D2D1_SIZE_F size;
        //    size.width = player.hurtbox.right - player.hurtbox.left;
        //    size.height = player.hurtbox.bottom - player.hurtbox.top;
        //    D2D1_RECT_F destRect = D2D1::RectF(player.hurtbox.left, player.hurtbox.top,
        //        size.width + player.hurtbox.left, size.height + player.hurtbox.top);
        //    pRenderTarget->DrawBitmap(playerHurtBoxBitmap, destRect);
        //}

        // Get weapon bitmap
        ID2D1Bitmap* playerWeaponFrameBitmap = pBitmaps[player.weaponFileName];

        // Render weapon
        if (playerWeaponFrameBitmap)
        {
            D2D1_SIZE_F size = playerWeaponFrameBitmap->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(player.weaponXPosition, player.weaponYPosition,
                (size.width * scalerX) + player.weaponXPosition, (size.height * scalerY) + player.weaponYPosition);
            pRenderTarget->DrawBitmap(playerWeaponFrameBitmap, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
        }

        HRESULT hr = S_OK;

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
            hr = pRenderTarget->CreateSolidColorBrush(
                D2D1::ColorF(D2D1::ColorF::White),
                &pBrush
            );
        }

        // Get HP Bar Shell Bitmap
        ID2D1Bitmap* playerHPBarShell = pBitmaps[hpBarShell];

        // Render HP Bar SHell
        if (playerHPBarShell)
        {
            D2D1_SIZE_F size = playerHPBarShell->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(rightBorder - (3 * size.width) - 10, 0 + 10,
                rightBorder - 10, 10 + (3 * size.height));
            pRenderTarget->DrawBitmap(playerHPBarShell, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

            // Draw HP total
            WCHAR buffer[128];
            swprintf_s(buffer, L"%.0f/%.0f", player.HP, player.maxHP);
            D2D1_RECT_F layoutRect = D2D1::RectF(rightBorder - (3 * size.width) - 200, 24, rightBorder - (3 * size.width) - 15, size.height / 2 + 38);
            pRenderTarget->DrawText(
                buffer,
                wcslen(buffer),
                pTextFormat,
                layoutRect,
                pBrush
            );
        }

        // Get HP Bar filling bitmap
        ID2D1Bitmap* playerHPBarFilling = pBitmaps[hpBarFilling];

        // Render HP Bar Filling
        if (playerHPBarFilling)
        {
            D2D1_SIZE_F size = playerHPBarFilling->GetSize();

            // Get ratio based on player's current HP
            double hpRatio = player.HP / player.maxHP;
            unsigned int hpBarWidth = size.width * hpRatio;

            D2D1_RECT_F srcRect = D2D1::RectF(0, 0, hpBarWidth, size.height);

            double w = ((size.width) - 13) * 3;
            double h = size.height * 3;

            D2D1_RECT_F destRect = D2D1::RectF(rightBorder - (3 * size.width) - 13, 10,
                rightBorder - (3 * size.width) - 13 + (3 * hpBarWidth), 10 + h);

            pRenderTarget->DrawBitmap(playerHPBarFilling, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
        }

        // Get MP Bar Shell Bitmap
        ID2D1Bitmap* playerMPBarShell = pBitmaps[mpBarShell];

        // Render MP Bar Shell
        if (playerMPBarShell)
        {
            D2D1_SIZE_F size = playerMPBarShell->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(rightBorder - (3 * size.width) - 10, 10 + (3 * size.height),
                rightBorder - 10, 10 + (6 * size.height));
            pRenderTarget->DrawBitmap(playerMPBarShell, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

            // Draw MP total
            WCHAR buffer[128];
            swprintf_s(buffer, L"%.0f/%.0f", player.MP, player.maxMP);
            D2D1_RECT_F layoutRect = D2D1::RectF(rightBorder - (3 * size.width) - 200, 78, rightBorder - (3 * size.width) - 15, size.height + 300);
            pRenderTarget->DrawText(
                buffer,
                wcslen(buffer),
                pTextFormat,
                layoutRect,
                pBrush
            );
        }

        // Get MP Bar Filling bitmap
        ID2D1Bitmap* playerMPBarFilling = pBitmaps[mpBarFilling];

        // Render MP Bar Filling
        if (playerMPBarFilling)
        {
            D2D1_SIZE_F size = playerMPBarFilling->GetSize();

            double mpRatio = player.MP / player.maxMP;
            unsigned int mpBarWidth = size.width * mpRatio;

            D2D1_RECT_F srcRect = D2D1::RectF(0, 0, mpBarWidth, size.height);

            D2D1_RECT_F destRect = D2D1::RectF(rightBorder - (3 * size.width) - 13, 10 + (3 * size.height),
                rightBorder - (3 * size.width) - 13 + (3 * mpBarWidth), 10 + (6 * size.height));

            pRenderTarget->DrawBitmap(playerMPBarFilling, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
        }

        // EXP Bar Shell
        ID2D1Bitmap* playerEXPBarShell = pBitmaps[expBarShell];

        if (playerEXPBarShell)
        {
            D2D1_SIZE_F size = playerEXPBarShell->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(rightBorder - (3 * size.width) - 10, 122,
                rightBorder - 10, 134);
            pRenderTarget->DrawBitmap(playerEXPBarShell, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
        }

        // EXP Bar Filling
        ID2D1Bitmap* playerEXPBarFilling = pBitmaps[expBarFilling];

        if (playerEXPBarFilling)
        {
            D2D1_SIZE_F size = playerEXPBarFilling->GetSize();

            double expRatio = player.exp / player.levelup;
            if (expRatio > 1) {
                expRatio = 1;
            }
            unsigned int expBarWidth = size.width * expRatio;

            D2D1_RECT_F srcRect = D2D1::RectF(0, 0, expBarWidth, size.height);

            D2D1_RECT_F destRect = D2D1::RectF(rightBorder - (3 * size.width) - 13, 122,
                rightBorder - (3 * size.width) - 13 + (3 * expBarWidth), 134);

            pRenderTarget->DrawBitmap(playerEXPBarFilling, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
        }

        // Skill Panes
        ID2D1Bitmap* playerSkillPanes = pBitmaps[skillPanes];

        if (playerSkillPanes)
        {
            int offset = 20;
            D2D1_SIZE_F size = playerSkillPanes->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(leftBorder + offset, offset, offset + 4 * size.width, offset + 4 * size.height);
            pRenderTarget->DrawBitmap(playerSkillPanes, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
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
            hr = pRenderTarget->CreateSolidColorBrush(
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
                } else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_2) {
                    player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_3;
                    player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                    player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                } else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_3) {
                    player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_4;
                    player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                    player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                } else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_4) {
                    player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_5;
                    player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                    player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                } else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_5) {
                    player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_6;
                    player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                    player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                } else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_6) {
                    player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_7;
                    player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                    player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                } else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_7) {
                    player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_8;
                    player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                    player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                } else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_8) {
                    player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_9;
                    player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                    player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                } else if (player.lastLevelUpOverworldTextFileName == Level_Up_Overworld_Text_9 &&
                           std::chrono::steady_clock::now() - player.lastLevelUpOverworldTextTime >= std::chrono::milliseconds(250)) {
                    player.levelUpOverworldTextFileName = Level_Up_Overworld_Text_1;
                    player.lastLevelUpOverworldTextFileName = player.levelUpOverworldTextFileName;
                    player.lastLevelUpOverworldTextTime = std::chrono::steady_clock::now();
                }

                
            }

            // Get level up overworld text bitmap
            ID2D1Bitmap* level_Up_Overworld_Text = pBitmaps[player.levelUpOverworldTextFileName];
            

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
                pRenderTarget->DrawBitmap(level_Up_Overworld_Text, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
            }
        }

        // If the player has leveled up
        if (player.inLevelUpSequence == true && player.inLevelUpFanfare == false) {
            // Get level up screen shell bitmap
            ID2D1Bitmap* shellBitmap = pBitmaps[Focused_Level_Up_Screen_Shell];

            // Render level up screen shell
            if (shellBitmap)
            {
                D2D1_SIZE_F size = shellBitmap->GetSize();
                D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (64 * scalerX), 1 * scalerY,
                                                  ((leftBorder + (64 * scalerX))) + (size.width * scalerX), ((size.height + 1) * scalerY));
                pRenderTarget->DrawBitmap(shellBitmap, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
            }

            int yArrowOffset;

            // Get stats bitmap
            ID2D1Bitmap* strStat1;
            ID2D1Bitmap* strStat2;
            ID2D1Bitmap* strStat3;
            if (player.statSelection == 0) {
                TranslateStatstoBitmap(player.strength, strStat1, strStat2, strStat3, true);
                yArrowOffset = 41;
            }
            else {
                TranslateStatstoBitmap(player.strength, strStat1, strStat2, strStat3, false);
            }

            ID2D1Bitmap* dexStat1;
            ID2D1Bitmap* dexStat2;
            ID2D1Bitmap* dexStat3;
            if (player.statSelection == 1) {
                TranslateStatstoBitmap(player.dexterity, dexStat1, dexStat2, dexStat3, true);
                yArrowOffset = 60;
            } else {
                TranslateStatstoBitmap(player.dexterity, dexStat1, dexStat2, dexStat3, false);
            }

            ID2D1Bitmap* intStat1;
            ID2D1Bitmap* intStat2;
            ID2D1Bitmap* intStat3;
            if (player.statSelection == 2) {
                TranslateStatstoBitmap(player.intelligence, intStat1, intStat2, intStat3, true);
                yArrowOffset = 79;
            }
            else {
                TranslateStatstoBitmap(player.intelligence, intStat1, intStat2, intStat3, false);
            }

            ID2D1Bitmap* wisStat1;
            ID2D1Bitmap* wisStat2;
            ID2D1Bitmap* wisStat3;
            if (player.statSelection == 3) {
                TranslateStatstoBitmap(player.wisdom, wisStat1, wisStat2, wisStat3, true);
                yArrowOffset = 98;
            }
            else {
                TranslateStatstoBitmap(player.wisdom, wisStat1, wisStat2, wisStat3, false);
            }

            ID2D1Bitmap* defStat1;
            ID2D1Bitmap* defStat2;
            ID2D1Bitmap* defStat3;
            if (player.statSelection == 4) {
                TranslateStatstoBitmap(player.defense, defStat1, defStat2, defStat3, true);
                yArrowOffset = 117;
            }
            else {
                TranslateStatstoBitmap(player.defense, defStat1, defStat2, defStat3, false);
            }

            ID2D1Bitmap* mDefStat1;
            ID2D1Bitmap* mDefStat2;
            ID2D1Bitmap* mDefStat3;
            if (player.statSelection == 5) {
                TranslateStatstoBitmap(player.magicDefense, mDefStat1, mDefStat2, mDefStat3, true);
                yArrowOffset = 136;
            }
            else {
                TranslateStatstoBitmap(player.magicDefense, mDefStat1, mDefStat2, mDefStat3, false);
            }

            ID2D1Bitmap* tDefStat1;
            ID2D1Bitmap* tDefStat2;
            ID2D1Bitmap* tDefStat3;
            if (player.statSelection == 6) {
                TranslateStatstoBitmap(player.trueDefense, tDefStat1, tDefStat2, tDefStat3, true);
                yArrowOffset = 155;
            }
            else {
                TranslateStatstoBitmap(player.trueDefense, tDefStat1, tDefStat2, tDefStat3, false);
            }

            ID2D1Bitmap* agiStat1;
            ID2D1Bitmap* agiStat2;
            ID2D1Bitmap* agiStat3;
            if (player.statSelection == 7) {
                TranslateStatstoBitmap(player.agility, agiStat1, agiStat2, agiStat3, true);
                yArrowOffset = 174;
            }
            else {
                TranslateStatstoBitmap(player.agility, agiStat1, agiStat2, agiStat3, false);
            }

            ID2D1Bitmap* luckStat1;
            ID2D1Bitmap* luckStat2;
            ID2D1Bitmap* luckStat3;
            if (player.statSelection == 8) {
                TranslateStatstoBitmap(player.luck, luckStat1, luckStat2, luckStat3, true);
                yArrowOffset = 193;
            }
            else {
                TranslateStatstoBitmap(player.luck, luckStat1, luckStat2, luckStat3, false);
            }

            // Render stats
            RenderStats(strStat1, strStat2, strStat3, 41);
            RenderStats(dexStat1, dexStat2, dexStat3, 60);
            RenderStats(intStat1, intStat2, intStat3, 79);
            RenderStats(wisStat1, wisStat2, wisStat3, 98);
            RenderStats(defStat1, defStat2, defStat3, 117);
            RenderStats(mDefStat1, mDefStat2, mDefStat3, 136);
            RenderStats(tDefStat1, tDefStat2, tDefStat3, 155);
            RenderStats(agiStat1, agiStat2, agiStat3, 174);
            RenderStats(luckStat1, luckStat2, luckStat3, 193);

            //Up and down arrows render
            if (player.statSelected) {
                // Get confirm button bitmap
                ID2D1Bitmap* arrows = pBitmaps[Focused_Level_Up_Down_Arrow];

                // Render confirm button
                if (arrows)
                {
                    D2D1_SIZE_F size = arrows->GetSize();
                    D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (177 * scalerX), yArrowOffset * scalerY,
                        ((leftBorder + (177 * scalerX))) + (size.width * scalerX), ((size.height + yArrowOffset) * scalerY));
                    pRenderTarget->DrawBitmap(arrows, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
                }
            }

            // Get back button bitmap
            ID2D1Bitmap* backButtonBitmap;
            LPCWSTR filename = player.lastBackButtonFile;
            if (player.statSelection == 9 &&
                (std::chrono::steady_clock::now() - player.backButtonAnimationInterval > std::chrono::milliseconds(500)))
            {
                player.backButtonAnimationInterval = std::chrono::steady_clock::now();
                if (player.lastBackButtonFile == Level_Up_Back_Button_Unpressed) {
                    filename = Level_Up_Back_Button_Pressed;
                    player.lastBackButtonFile = Level_Up_Back_Button_Pressed;
                }
                else {
                    filename = Level_Up_Back_Button_Unpressed;
                    player.lastBackButtonFile = Level_Up_Back_Button_Unpressed;
                }
            }
            if (player.statSelection != 9) {
                filename = Level_Up_Back_Button_Unpressed;
                player.lastBackButtonFile = Level_Up_Back_Button_Unpressed;
            }

            backButtonBitmap = pBitmaps[filename];

            // Render back button
            if (backButtonBitmap)
            {
                
                D2D1_SIZE_F size = backButtonBitmap->GetSize();
                D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (84 * scalerX), 207 * scalerY,
                    ((leftBorder + (84 * scalerX))) + (size.width * scalerX), ((size.height + 207) * scalerY));
                pRenderTarget->DrawBitmap(backButtonBitmap, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
            }

            // Get confirm button bitmap
            ID2D1Bitmap* confirmButtonBitmap = pBitmaps[Level_Up_Confirm_Button_Unpressed];

            // Render confirm button
            if (confirmButtonBitmap)
            {
                D2D1_SIZE_F size = confirmButtonBitmap->GetSize();
                D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (135 * scalerX), 207 * scalerY,
                    ((leftBorder + (135 * scalerX))) + (size.width * scalerX), ((size.height + 207) * scalerY));
                pRenderTarget->DrawBitmap(confirmButtonBitmap, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
            }
            

            //// Get confirm bitmap
            //ID2D1Bitmap* confirmButton = pBitmaps[Level_Up_Confirm_Button_Unpressed];
            //// Render confirm button
            //if (focusedLevelUpBitmap)
            //{
            //    D2D1_SIZE_F size = confirmButton->GetSize();
            //    D2D1_RECT_F destRect = D2D1::RectF(leftBorder + (64 * scalerX), 1 * scalerY,
            //        ((leftBorder + (64 * scalerX))) + (size.width * scalerX), ((size.height + 1) * scalerY));
            //    pRenderTarget->DrawBitmap(confirmButton, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
            //}


        }

        //// Weapn Hitbox
        //ID2D1Bitmap* playerHitBoxBitmap = pBitmaps[playerHitBox];

        //if (playerHitBoxBitmap && playerWeaponFrameBitmap)
        //{
        //    D2D1_SIZE_F size = playerWeaponFrameBitmap->GetSize();
        //    D2D1_RECT_F destRect = D2D1::RectF(player.weaponXPosition, player.weaponYPosition,
        //        (size.width * scalerX) + player.weaponXPosition, (size.height * scalerY) + player.weaponYPosition);
        //    pRenderTarget->DrawBitmap(playerHitBoxBitmap, destRect);
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
        //    pRenderTarget->DrawText(
        //        buffer,
        //        wcslen(buffer),
        //        pTextFormat,
        //        layoutRect,
        //        pBrush
        //    );

        //}

        hr = pRenderTarget->EndDraw();

        if (hr == D2DERR_RECREATE_TARGET)
        {
            DiscardDeviceResources();
        }
    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

std::vector<LPCWSTR> spriteData;
Player player;
Enemy leafEnemy[1];
std::vector<Enemy> enemies; 
int startingStats[9];
std::chrono::steady_clock::time_point currentFrameTime = std::chrono::steady_clock::now(); // Keeps tracks of screen updates
std::chrono::steady_clock::time_point debugTimer = std::chrono::steady_clock::now();

void UpdateGameLogic(double deltaSeconds) {
    if (!player.inLevelUpSequence) {
        // Enemy Movement and Animations
        for (int i = 0; i < enemies.size(); i++)
        {
            if (enemies.at(i).framesWalked2 % 288 == 0 && (std::chrono::steady_clock::now() - enemies.at(i).hitStunStartTime) >= enemies.at(i).hitStunTime)
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
            }
        }

        // Player Actions, Movement, and Animations
        double xDir, yDir;
        if (keys.space == false && player.isBasicAttacking == false)
        {
            GetDirectionalInput(xDir, yDir, keys.right, keys.left, keys.down, keys.up);
            if ((xDir != 0 || yDir != 0)) {
                xDir *= 2.5;
                yDir *= 2.5;
                if (keys.lShift == true)
                {
                    xDir *= 1.4;
                    yDir *= 1.4;
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


        else if (keys.space == true || player.isBasicAttacking == true)
        {
            player.BasicAttack(enemies);
        }

        if (player.exp >= player.levelup) {
            player.PlayerLevelUpSequence();
        }
    }
    else
    {
        if (player.inLevelUpFanfare) {
            if ((std::chrono::steady_clock::now() - player.levelUpFanfareBegin) >= std::chrono::seconds(1)) {
                player.inLevelUpFanfare = false;
            }
            startingStats[0] = player.strength;
            startingStats[1] = player.dexterity;
            startingStats[2] = player.intelligence;
            startingStats[3] = player.wisdom;
            startingStats[4] = player.defense;
            startingStats[5] = player.magicDefense;
            startingStats[6] = player.trueDefense;
            startingStats[7] = player.agility;
            startingStats[8] = player.luck;

        }
        else
        {
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

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
    srand(time(NULL));

    // Load all Sprites
    StoreSpriteFileNames(spriteData);

    // Load Enemy Info
    populateEnemyExpList();

    std::vector<bool> calendar(365, false);

    enemies.reserve(1);
    for (int i = 0; i < 0; i++)
    {
        enemies.emplace_back(leafEnemy[i]);
    }

    lastUpdate = std::chrono::steady_clock::now();
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
            break;
        case VK_RIGHT:
            keys.right = true;
            break;
        case VK_UP:
            keys.up = true;
            break;
        case VK_DOWN:
            keys.down = true;
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
            break;
        case VK_RIGHT:
            keys.right = false;
            break;
        case VK_UP:
            keys.up = false;
            break;
        case VK_DOWN:
            keys.down = false;
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
        }
        InvalidateRect(hWnd, NULL, true);
        break;
    }

    case WM_PAINT:
    case WM_DISPLAYCHANGE:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        std::chrono::duration<double> deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - timeSinceLogicUpdate);
        double deltaSeconds = deltaTime.count() * 100;
        timeSinceLogicUpdate = std::chrono::steady_clock::now();
        UpdateGameLogic(deltaSeconds);

        Render(hWnd, spriteData, player, enemies);

        EndPaint(hWnd, &ps);

        InvalidateRect(hWnd, NULL, FALSE);
    } break;

    case WM_DESTROY: {
        DiscardDeviceResources();
        PostQuitMessage(0);
    } break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    if (keys.escape == true) {
        DiscardDeviceResources();
        PostQuitMessage(0);
    }

    return 0;
}