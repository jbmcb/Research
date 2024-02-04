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

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "windowscodecs.lib")
#pragma comment(lib, "dwrite.lib")


// Contains all filenames necessary for the game to run. Condensed into variables to improve readability in later code.
LPCWSTR playerStationaryDown = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationarydown.png";
LPCWSTR playerWalkingDownLeft = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerwalkingdownleft.png";
LPCWSTR playerWalkingDownRight = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerwalkingdownright.png";
LPCWSTR playerStationaryUp = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationaryup.png";
LPCWSTR playerWalkingUpLeft = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerwalkingupleft.png";
LPCWSTR playerWalkingUpRight = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerwalkingupright.png";
LPCWSTR playerStationaryLeft = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationaryleft.png";
LPCWSTR playerWalkingLeftLeft = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerwalkingleftleft.png";
LPCWSTR playerWalkingLeftRight = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerwalkingleftright.png";
LPCWSTR playerStationaryRight = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationaryright.png";
LPCWSTR playerWalkingRightLeft = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerwalkingrightleft.png";
LPCWSTR playerWalkingRightRight = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerwalkingrightright.png";
LPCWSTR playerHurtBox = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Debug\\hurtbox.png";
LPCWSTR playerStationaryUpBasicAttack1 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationaryupbasicattack1.png";
LPCWSTR playerStationaryUpBasicAttack2 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationaryupbasicattack2.png";
LPCWSTR playerStationaryUpBasicAttack3 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationaryupbasicattack3.png";
LPCWSTR playerStationaryUpBasicAttack4 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationaryupbasicattack4.png";
LPCWSTR playerStationaryUpBasicAttack5 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationaryupbasicattack5.png";
LPCWSTR playerStationaryUpBasicAttack6 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationaryupbasicattack6.png";
LPCWSTR playerStationaryUpBasicAttack7 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Player\\playerstationaryupbasicattack7.png";
LPCWSTR testSwordBasicAttackUp1 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Weapons\\testswordbasicattackup1.png";
LPCWSTR testSwordBasicAttackUp2 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Weapons\\testswordbasicattackup2.png";
LPCWSTR testSwordBasicAttackUp3 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Weapons\\testswordbasicattackup3.png";
LPCWSTR testSwordBasicAttackUp4 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Weapons\\testswordbasicattackup4.png";
LPCWSTR testSwordBasicAttackUp5 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Weapons\\testswordbasicattackup5.png";
LPCWSTR testSwordBasicAttackUp6 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Weapons\\testswordbasicattackup6.png";
LPCWSTR testSwordBasicAttackUp7 = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Weapons\\testswordbasicattackup7.png";
LPCWSTR playerHitBox = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Debug\\hitbox.png";

LPCWSTR leafEnemyStationary = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Enemies\\LeafDownStationary.png";
LPCWSTR leafEnemyDownWalkingLeft = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Enemies\\LeafDownWalkingLeft.png";
LPCWSTR leafEnemyDownWalkingRight = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Enemies\\LeafDownWalkingRight.png";
LPCWSTR leafEnemyDownHitstun = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Enemies\\LeafDownHitstun.png";

LPCWSTR testBackground = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\Environment\\testBackground.png";

LPCWSTR hpBarShell = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\UI\\HPBar_Shell.png";
LPCWSTR hpBarFilling = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\UI\\HPBar_Filling.png";
LPCWSTR mpBarShell = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\UI\\MPBar_Shell.png";
LPCWSTR mpBarFilling = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\UI\\MPBar_Filling.png";
LPCWSTR expBarShell = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\UI\\EXPBar_Shell.png";
LPCWSTR expBarFilling = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\UI\\EXPBar_Filling.png";

LPCWSTR skillPanes = L"C:\\Users\\receiving\\source\\repos\\Research\\Research\\Sprites\\UI\\Skill Panes.png";

// ID2D1Factory interface is the starting point for using Direct2D; it's what you use to create other Direct2D resources
ID2D1Factory* pD2DFactory = NULL;

// ID2D1HwndRenderTarget represents an object that can receive drawing commands.
ID2D1HwndRenderTarget* pRenderTarget = NULL;

// ID2D1Bitmap represents a bitmap that has been bound to an ID2D1RenderTarget
std::map<LPCWSTR, ID2D1Bitmap*> pBitmaps;

// IDWriteFactory interface is the root factory interface for all DirectWrite objects, used for text
IDWriteFactory* pDWriteFactory = NULL;

// IDWriteTextFormat interface describes the font and paragraph properties used to format text, and it describes locale information.
IDWriteTextFormat* pTextFormat = NULL;

// System screen horizontal and vertical resolution
int sysScreenX = GetSystemMetrics(SM_CXSCREEN);
int sysScreenY = GetSystemMetrics(SM_CYSCREEN);

double scalerX = sysScreenX / 398;
double scalerY = sysScreenY / 224;

// Total number of frames
unsigned long long int frameCount = 0;

// Indexes the last time the fps was updated
std::chrono::time_point<std::chrono::steady_clock> lastUpdate;

// framerate
double fps = 0.0;

// ID2D1SolidColorBrush paints an area with a solid color.
ID2D1SolidColorBrush* pBrush = NULL;

// Index files
std::vector<LPCWSTR> filePaths;

// Use the steady_clock for timing to prevent issues with time changes
std::chrono::steady_clock::time_point lastMoveTime = std::chrono::steady_clock::now();

double moveInterval = 1 / 500; // Move every 0.002 seconds


// contains booleans for key presses
struct
{
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool space = false;
    bool lShift = false;
    bool escape = false;
} keys;

void GetDirectionalInput(double& xDirection, double& yDirection, bool keyRight, bool keyLeft, bool keyDown, bool keyUp)
{
    xDirection = (keyRight ? 1 : 0) - (keyLeft ? 1 : 0);
    yDirection = (keyDown ? 1 : 0) - (keyUp ? 1 : 0);
}

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
        fileNameChanged = true; // Flag that the filename has changed
    }

    void DestroyObject()
    {
        fileName = nullptr;
        fileNameChanged = true;
    }
};

class Enemy : public Object
{
public:

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
        fileNameChanged = true;
        SetEnemyHurtBox();
    }

    void SetEnemyHurtBox()
    {
        // Get the bitmap for the current object frame
        ID2D1Bitmap* pBitmap = pBitmaps[fileName];
        if (pBitmap)
        {
            D2D1_SIZE_F size = pBitmap->GetSize();
            hurtbox = D2D1::RectF(xPosition + 10, yPosition + 10,
                size.width + xPosition - 20, size.height + yPosition);
        }

    }

    // Displaces the Object
    void MoveEnemy(double xDirection, double yDirection)
    {
        xPosition += xDirection;
        yPosition += yDirection;

        lastXDirection2 = xDirection;
        lastYDirection2 = yDirection;
        SetEnemyHurtBox();
    }

    // Displaces the Object
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
            if (lastfilepath == nullptr)
            {
                fileName = leafEnemyDownWalkingLeft;
                lastfilepath = fileName;
            }
            else if (lastfilepath == leafEnemyDownWalkingLeft && secondlastfilepath == nullptr)
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
            else if (lastfilepath == leafEnemyDownWalkingLeft && secondlastfilepath == leafEnemyStationary)
            {
                fileName = leafEnemyStationary;
                lastfilepath = fileName;
                secondlastfilepath = leafEnemyDownWalkingLeft;
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

    int level = 1;
    double exp = 0;
    double levelup = 100;

    double HP = 100;
    double maxHP = 100;
    double MP = 50;
    double maxMP = 50;
    int strength = 9;
    int dexterity = 10;
    int intelligence = 5;
    int wisdom = 7;
    int defense = 5;
    int magicDefense = 3;
    int trueDefense = 1;
    int speed = 10;
    int luck = 8;

    std::chrono::steady_clock::time_point lastBasicAttackFrame = std::chrono::steady_clock::now();
    std::chrono::nanoseconds basicAttackFrameIncrements = std::chrono::nanoseconds(16666666 / 32);
    std::chrono::nanoseconds basicAttackStartLag = std::chrono::nanoseconds(66666666);
    std::chrono::nanoseconds basicAttackEndLag = std::chrono::nanoseconds(133333333);
    std::chrono::nanoseconds hitLag = std::chrono::nanoseconds(0);
    std::chrono::nanoseconds walkAnimationInterval = std::chrono::nanoseconds(166666666);
    bool isBasicAttacking = false;
    LPCWSTR weaponFileName;
    double weaponXPosition = xPosition;
    double weaponYPosition = yPosition;
    int basicAttackFrameThresholds = 1;
    D2D1_RECT_F hitbox;
    bool madeContact = false;
    bool frameAdvanced = false;
    LPCWSTR hpBarFileName;

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
    {
        if (std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - lastWalkTime) >= walkAnimationInterval
            || (yDirection == 0 && (((abs(xDirection) - abs(lastXDirection)) != 0)) || (xDirection == 0 && ((abs(yDirection) - abs(lastYDirection)) != 0)))
            || (yDirection == 0 && ((xDirection * lastXDirection) < 0) || (xDirection == 0 && (yDirection * lastYDirection) < 0)))
        {
            // This section accounts for diagonal movement. The player should animate in the same direction they were facing before 
            // they started moving diagonally
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

            // If diagonal movement isn't detected, then animate in the direction the player is facing
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

            lastWalkTime = std::chrono::steady_clock::now(); // reset the frame counter
            fileNameChanged = true; // Flag that the filename has changed
        }
    }

    // Sets the hurtbox for the object. This is how the game knows if the player has been hit or is touching something.
    void SetPlayerHurtBox()
    {
        // Get the bitmap for the current object frame
        ID2D1Bitmap* pBitmap = pBitmaps[fileName];
        if (pBitmap)
        {
            D2D1_SIZE_F size = pBitmap->GetSize();
            hurtbox = D2D1::RectF(xPosition + 30, yPosition + 10,
                size.width + xPosition - 30, size.height + yPosition - 15);
        }

    }

    // Displaces the Object
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
            SwapAttackFrames(playerStationaryUpBasicAttack1, playerStationaryUp, testSwordBasicAttackUp1);

            weaponXPosition = xPosition + 108;
            weaponYPosition = yPosition + 99;
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            isBasicAttacking = true;
            hitLag = std::chrono::nanoseconds(0);

        }
        else if (lastfilepath == playerStationaryUp || lastfilepath == playerWalkingUpLeft || lastfilepath == playerWalkingUpRight)
        {
            SwapAttackFrames(playerStationaryUpBasicAttack1, playerStationaryUp, testSwordBasicAttackUp1);

            weaponXPosition = xPosition + 108;
            weaponYPosition = yPosition + 99;
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            isBasicAttacking = true;
            hitLag = std::chrono::nanoseconds(0);

        }
        else if (lastfilepath == playerStationaryUpBasicAttack1
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= (hitLag + basicAttackFrameIncrements * 10))
        {
            SwapAttackFrames(playerStationaryUpBasicAttack2, playerStationaryUpBasicAttack1, testSwordBasicAttackUp2);

            weaponXPosition = xPosition + 108;
            weaponYPosition = yPosition;
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            hitLag = std::chrono::nanoseconds(0);
        }
        else if (lastfilepath == playerStationaryUpBasicAttack2
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + basicAttackFrameIncrements * 10)
        {
            SwapAttackFrames(playerStationaryUpBasicAttack3, playerStationaryUpBasicAttack2, testSwordBasicAttackUp3);

            weaponXPosition = xPosition + 99;
            weaponYPosition = yPosition - 81;
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            hitLag = std::chrono::nanoseconds(0);
        }
        else if (lastfilepath == playerStationaryUpBasicAttack3
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + basicAttackFrameIncrements * 10)
        {
            SwapAttackFrames(playerStationaryUpBasicAttack4, playerStationaryUpBasicAttack3, testSwordBasicAttackUp4);

            weaponXPosition = xPosition + 45;
            weaponYPosition = yPosition - 108;
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            hitLag = std::chrono::nanoseconds(0);
        }
        else if (lastfilepath == playerStationaryUpBasicAttack4
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + basicAttackFrameIncrements * 10)
        {
            SwapAttackFrames(playerStationaryUpBasicAttack5, playerStationaryUpBasicAttack4, testSwordBasicAttackUp5);

            weaponXPosition = xPosition - 54;
            weaponYPosition = yPosition - 81;
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            hitLag = std::chrono::nanoseconds(0);
        }
        else if (lastfilepath == playerStationaryUpBasicAttack5
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + basicAttackFrameIncrements * 10)
        {
            SwapAttackFrames(playerStationaryUpBasicAttack6, playerStationaryUpBasicAttack5, testSwordBasicAttackUp6);

            weaponXPosition = xPosition - 135;
            weaponYPosition = yPosition - 54;
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            hitLag = std::chrono::nanoseconds(0);
        }
        else if (lastfilepath == playerStationaryUpBasicAttack6
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= hitLag + (basicAttackFrameIncrements * 3))
        {
            SwapAttackFrames(playerStationaryUpBasicAttack7, playerStationaryUpBasicAttack6, testSwordBasicAttackUp7);

            weaponXPosition = xPosition - 162;
            weaponYPosition = yPosition + 9;
            SetHitBox();
            SetPlayerHurtBox();
            basicAttackFrameThresholds += 1;
            lastBasicAttackFrame = std::chrono::steady_clock::now();
            hitLag = std::chrono::nanoseconds(0);
        }
        else if (lastfilepath == playerStationaryUpBasicAttack7
            && std::chrono::steady_clock::now() - lastBasicAttackFrame >= basicAttackEndLag + (hitLag + (basicAttackFrameIncrements))
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
            hitLag = std::chrono::nanoseconds(0);
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

        if (true)
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
                        enemies.at(i).hp -= strength;
                        /*double nanoseconds = (static_cast<double>(attack) / static_cast<double>(enemies.at(i).maxHP)) * 333333333;
                        hitLag = std::chrono::nanoseconds((static_cast<int>(nanoseconds)));*/

                        if (enemies.at(i).hp <= 0)
                        {
                            exp += 10;
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
        // Get the bitmap for the current object frame
        ID2D1Bitmap* pBitmap = pBitmaps[weaponFileName];
        if (pBitmap)
        {
            D2D1_SIZE_F size = pBitmap->GetSize();
            hitbox = D2D1::RectF(weaponXPosition, weaponYPosition,
                size.width + weaponXPosition, size.height + weaponYPosition);
        }
    }

    void RemoveHitBox()
    {
        hitbox.right = hitbox.left = hitbox.top = hitbox.bottom = -1;
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

void ApplyPlayerDirectionalInput(Player& player, std::chrono::duration<float> elapsedTime, std::chrono::steady_clock::time_point currentFrameTime, double xDir, double yDir)
{
    if ((xDir != 0 || yDir != 0) && player.hurtbox.left >= 0 && player.hurtbox.top >= 0
        && player.hurtbox.right <= sysScreenX && player.hurtbox.bottom <= sysScreenY)
    {
        player.MovePlayer(xDir, yDir);
        if (player.hurtbox.left >= 0 && player.hurtbox.top >= 0
            && player.hurtbox.right <= sysScreenX && player.hurtbox.bottom <= sysScreenY)
        {
            player.PlayerWalkAnimation(3 * xDir, 3 * yDir);
        }
        else
        {
            player.PlayerIdle();
        }

        // If the player was moved out of bounds, snaps them back in bounds
        if (player.hurtbox.left <= 0)
        {
            player.MovePlayer(0 - player.hurtbox.left, 0);
        }
        if (player.hurtbox.top <= 0)
        {
            player.MovePlayer(0, 0 - player.hurtbox.top);
        }
        if (player.hurtbox.right >= sysScreenX)
        {
            player.MovePlayer(sysScreenX - player.hurtbox.right, 0);
        }
        if (player.hurtbox.bottom >= sysScreenY)
        {
            player.MovePlayer(0, sysScreenY - player.hurtbox.bottom);
        }
    }
    else
    {
        player.PlayerIdle();
    }
}

void ApplyEnemyDirectionalInput(Enemy& enemy, double xDir, double yDir)
{
    enemy.SetEnemyHurtBox();
    if (xDir != 0 || yDir != 0)
    {
        enemy.MoveEnemy(xDir, yDir);

        // If the enemy was moved out of bounds, snaps them back in bounds
        if (enemy.hurtbox.left <= 0)
        {
            enemy.DisplaceEnemy(0 - enemy.hurtbox.left, 0);
            enemy.lastXDirection2 *= -1;
        }
        if (enemy.hurtbox.top <= 0)
        {
            enemy.DisplaceEnemy(0, 0 - enemy.hurtbox.top);
            enemy.lastYDirection2 *= -1;
        }
        if (enemy.hurtbox.right >= sysScreenX)
        {
            enemy.DisplaceEnemy(sysScreenX - enemy.hurtbox.right, 0);
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

void LoadSpriteData(std::vector<Object>& spriteData)
{
    spriteData.reserve(40);

    //down stand and move
    spriteData.emplace_back();
    spriteData.at(0).WriteFileName(playerStationaryDown);
    spriteData.emplace_back();
    spriteData.at(1).WriteFileName(playerWalkingDownLeft);
    spriteData.emplace_back();
    spriteData.at(2).WriteFileName(playerWalkingDownRight);

    // up stand and move
    spriteData.emplace_back();
    spriteData.at(3).WriteFileName(playerStationaryUp);
    spriteData.emplace_back();
    spriteData.at(4).WriteFileName(playerWalkingUpLeft);
    spriteData.emplace_back();
    spriteData.at(5).WriteFileName(playerWalkingUpRight);

    // left stand and mnove
    spriteData.emplace_back();
    spriteData.at(6).WriteFileName(playerStationaryLeft);
    spriteData.emplace_back();
    spriteData.at(7).WriteFileName(playerWalkingLeftLeft);
    spriteData.emplace_back();
    spriteData.at(8).WriteFileName(playerWalkingLeftRight);

    // right stand and move
    spriteData.emplace_back();
    spriteData.at(9).WriteFileName(playerStationaryRight);
    spriteData.emplace_back();
    spriteData.at(10).WriteFileName(playerWalkingRightLeft);
    spriteData.emplace_back();
    spriteData.at(11).WriteFileName(playerWalkingRightRight);

    // player hurtbox
    spriteData.emplace_back();
    spriteData.at(12).WriteFileName(playerHurtBox);

    // player basic attack animation
    spriteData.emplace_back();
    spriteData.at(13).WriteFileName(playerStationaryUpBasicAttack1);
    spriteData.emplace_back();
    spriteData.at(14).WriteFileName(playerStationaryUpBasicAttack2);
    spriteData.emplace_back();
    spriteData.at(15).WriteFileName(playerStationaryUpBasicAttack3);
    spriteData.emplace_back();
    spriteData.at(16).WriteFileName(playerStationaryUpBasicAttack4);
    spriteData.emplace_back();
    spriteData.at(17).WriteFileName(playerStationaryUpBasicAttack5);
    spriteData.emplace_back();
    spriteData.at(18).WriteFileName(playerStationaryUpBasicAttack6);
    spriteData.emplace_back();
    spriteData.at(19).WriteFileName(playerStationaryUpBasicAttack7);

    // player weapon animations
    spriteData.emplace_back();
    spriteData.at(20).WriteFileName(testSwordBasicAttackUp1);
    spriteData.emplace_back();
    spriteData.at(21).WriteFileName(testSwordBasicAttackUp2);
    spriteData.emplace_back();
    spriteData.at(22).WriteFileName(testSwordBasicAttackUp3);
    spriteData.emplace_back();
    spriteData.at(23).WriteFileName(testSwordBasicAttackUp4);
    spriteData.emplace_back();
    spriteData.at(24).WriteFileName(testSwordBasicAttackUp5);
    spriteData.emplace_back();
    spriteData.at(25).WriteFileName(testSwordBasicAttackUp6);
    spriteData.emplace_back();
    spriteData.at(26).WriteFileName(testSwordBasicAttackUp7);

    // player hitbox
    spriteData.emplace_back();
    spriteData.at(27).WriteFileName(playerHitBox);

    // Leaf Enemy
    spriteData.emplace_back();
    spriteData.at(28).WriteFileName(leafEnemyStationary);
    spriteData.emplace_back();
    spriteData.at(29).WriteFileName(leafEnemyDownWalkingLeft);
    spriteData.emplace_back();
    spriteData.at(30).WriteFileName(leafEnemyDownWalkingRight);
    spriteData.emplace_back();
    spriteData.at(31).WriteFileName(leafEnemyDownHitstun);

    // Background
    spriteData.emplace_back();
    spriteData.at(32).WriteFileName(testBackground);

    // HP Bar
    spriteData.emplace_back();
    spriteData.at(33).WriteFileName(hpBarShell);
    spriteData.emplace_back();
    spriteData.at(34).WriteFileName(hpBarFilling);

    // MP Bar
    spriteData.emplace_back();
    spriteData.at(35).WriteFileName(mpBarShell);
    spriteData.emplace_back();
    spriteData.at(36).WriteFileName(mpBarFilling);

    // MP Bar
    spriteData.emplace_back();
    spriteData.at(37).WriteFileName(expBarShell);
    spriteData.emplace_back();
    spriteData.at(38).WriteFileName(expBarFilling);

    // Skill Panes
    spriteData.emplace_back();
    spriteData.at(39).WriteFileName(skillPanes);
}

//void CreateDeviceResources(HWND hWnd, Object objects)
//{
//    HRESULT hr = S_OK;
//
//    if (!pRenderTarget)
//    {
//        RECT rc;
//        GetClientRect(hWnd, &rc);
//
//        D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);
//
//        hr = pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hWnd, size), &pRenderTarget);
//    }
//
//    if (FAILED(hr))
//    {
//        return;
//    }
//
//    IWICImagingFactory* pWICFactory = NULL;
//    hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, reinterpret_cast<void**>(&pWICFactory));
//
//    if (FAILED(hr))
//    {
//        return;
//    }
//    if (objects.fileNameChanged || pBitmaps.find(objects.fileName) == pBitmaps.end())
//    {
//        IWICBitmapDecoder* pDecoder = NULL;
//        hr = pWICFactory->CreateDecoderFromFilename(objects.fileName,
//            NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder);
//
//        if (FAILED(hr))
//        {
//            pWICFactory->Release();
//            return;
//        }
//
//        IWICBitmapFrameDecode* pSource = NULL;
//        hr = pDecoder->GetFrame(0, &pSource);
//
//        if (FAILED(hr))
//        {
//            pDecoder->Release();
//            pWICFactory->Release();
//            return;
//        }
//
//        IWICFormatConverter* pConverter = NULL;
//        hr = pWICFactory->CreateFormatConverter(&pConverter);
//
//        if (FAILED(hr))
//        {
//            pSource->Release();
//            pDecoder->Release();
//            pWICFactory->Release();
//            return;
//        }
//
//        hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.0, WICBitmapPaletteTypeMedianCut);
//
//        if (FAILED(hr))
//        {
//            pConverter->Release();
//            pSource->Release();
//            pDecoder->Release();
//            pWICFactory->Release();
//            return;
//        }
//
//        ID2D1Bitmap* pBitmap = NULL; // Create new bitmap for each file
//        hr = pRenderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, &pBitmap);
//
//        if (SUCCEEDED(hr))
//        {
//            pBitmaps[objects.fileName] = pBitmap; // Add the new bitmap to our bitmap map
//            objects.fileNameChanged = false; // Reset the flag
//        }
//
//        // Release resources for each file
//        pConverter->Release();
//        pSource->Release();
//        pDecoder->Release();
//    }
//
//    // Release the WIC factory after processing all files
//    pWICFactory->Release();
//
//    // Create DirectWrite factory and text format for rendering FPS counter
//    hr = DWriteCreateFactory(
//        DWRITE_FACTORY_TYPE_SHARED,
//        __uuidof(IDWriteFactory),
//        reinterpret_cast<IUnknown**>(&pDWriteFactory)
//    );
//    if (SUCCEEDED(hr)) {
//        hr = pDWriteFactory->CreateTextFormat(
//            L"Arial",
//            NULL,
//            DWRITE_FONT_WEIGHT_NORMAL,
//            DWRITE_FONT_STYLE_NORMAL,
//            DWRITE_FONT_STRETCH_NORMAL,
//            20.0f,
//            L"en-us",
//            &pTextFormat
//        );
//    }
//
//    // Create the brush for text
//    if (SUCCEEDED(hr)) {
//        hr = pRenderTarget->CreateSolidColorBrush(
//            D2D1::ColorF(D2D1::ColorF::White),
//            &pBrush
//        );
//    }
//}

void CreateDeviceResources(HWND hWnd, std::vector<Object> spriteData)
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

    // Iterating over each file in the objects vector
    for (int i = 0; i < spriteData.size(); i++)
    {
        if (spriteData.at(i).fileNameChanged || pBitmaps.find(spriteData.at(i).fileName) == pBitmaps.end())
        {
            IWICBitmapDecoder* pDecoder = NULL;
            hr = pWICFactory->CreateDecoderFromFilename(spriteData.at(i).fileName,
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

            ID2D1Bitmap* pBitmap = NULL; // Create new bitmap for each file
            hr = pRenderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, &pBitmap);

            if (SUCCEEDED(hr))
            {
                pBitmaps[spriteData.at(i).fileName] = pBitmap; // Add the new bitmap to our bitmap map
                spriteData.at(i).fileNameChanged = false; // Reset the flag
            }

            // Release resources for each file
            pConverter->Release();
            pSource->Release();
            pDecoder->Release();
        }
    }

    // Release the WIC factory after processing all files
    pWICFactory->Release();

    // Create DirectWrite factory and text format for rendering FPS counter
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
}

void DiscardDeviceResources()
{
    // Release brush
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

//void OnRender(HWND hWnd, Object objects)
//{
//    if (!pRenderTarget)
//    {
//        CreateDeviceResources(hWnd, objects);
//    }
//
//    if (pRenderTarget)
//    {
//        pRenderTarget->BeginDraw();
//
//        // Get the bitmap for the current object from the map
//        ID2D1Bitmap* pBitmap = pBitmaps[objects.fileName];
//
//        // Draw the bitmap
//        if (pBitmap)
//        {
//            D2D1_SIZE_F size = pBitmap->GetSize();
//            D2D1_RECT_F destRect = D2D1::RectF(objects.xPosition, objects.yPosition,
//                size.width + objects.xPosition, size.height + objects.yPosition);
//            pRenderTarget->DrawBitmap(pBitmap, destRect);
//        }
//
//        if (pTextFormat && pBrush)
//        {
//            // Compute FPS if a quarter of a second or more has passed since last update
//            auto now = std::chrono::steady_clock::now();
//            std::chrono::duration<double> elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastUpdate);
//            if (elapsed.count() >= 0.25) {
//                fps = frameCount / elapsed.count();
//                frameCount = 0;
//                lastUpdate = now;
//            }
//
//            // Render FPS counter
//            WCHAR buffer[32];
//            swprintf_s(buffer, L"FPS: %.2f", fps);
//            D2D1_RECT_F layoutRect = D2D1::RectF(sysScreenX - 100, 0, sysScreenX, 20);
//            pRenderTarget->DrawText(
//                buffer,
//                wcslen(buffer),
//                pTextFormat,
//                layoutRect,
//                pBrush
//            );
//        }
//
//        HRESULT hr = pRenderTarget->EndDraw();
//        if (hr == D2DERR_RECREATE_TARGET)
//        {
//            DiscardDeviceResources();
//        }
//    }
//}

void OnRender(HWND hWnd, std::vector<Object> spriteData, Player player, std::vector<Enemy> enemies)
{
    if (!pRenderTarget)
    {
        CreateDeviceResources(hWnd, spriteData);
    }

    if (pRenderTarget)
    {
        pRenderTarget->BeginDraw();

        pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::DimGray));

        // Get Bitmap for background
        ID2D1Bitmap* background = pBitmaps[testBackground];

        // Draw background bitmap
        if (background)
        {
            D2D1_RECT_F destRect = D2D1::RectF(0, 0,
                sysScreenX, sysScreenY);
            pRenderTarget->DrawBitmap(background, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

        }

        // Get bitmap for and draw enemies
        for (int i = 0; i < enemies.size(); i++)
        {
            // Get the bitmap for the current player frame from the map
            ID2D1Bitmap* enemyFrameBitmap = pBitmaps[enemies.at(i).fileName];

            // Draw the Leaf enemy frame bitmap
            if (enemyFrameBitmap)
            {
                D2D1_SIZE_F size = enemyFrameBitmap->GetSize();
                D2D1_RECT_F destRect = D2D1::RectF(enemies.at(i).xPosition, enemies.at(i).yPosition,
                    (size.width * scalerX / 10) + enemies.at(i).xPosition, (size.height * scalerY / 10) + enemies.at(i).yPosition);
                pRenderTarget->DrawBitmap(enemyFrameBitmap, destRect);
            }

            /*LPCWSTR file_Name;
            if (enemies.at(i).damageTaken)
            {
                file_Name = playerHitBox;
            }
            else
            {
                file_Name = playerHurtBox;
            }*/

            //// Get the bitmap for the enemy hurtbox from the map
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

        // Get the bitmap for the current player frame from the map
        ID2D1Bitmap* playerFrameBitmap = pBitmaps[player.fileName];

        // Draw the player frame bitmap
        if (playerFrameBitmap)
        {
            D2D1_SIZE_F size = playerFrameBitmap->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(player.xPosition, player.yPosition,
                (size.width * scalerX / 10) + player.xPosition, (size.height * scalerY / 10) + player.yPosition);
            pRenderTarget->DrawBitmap(playerFrameBitmap, destRect);
        }

        //// Get the bitmap for the player hurtbox from the map
        //ID2D1Bitmap* playerHurtBoxBitmap = pBitmaps[playerHurtBox];

        //// Draw the hurtboxbitmap
        //if (playerHurtBoxBitmap)
        //{
        //    D2D1_SIZE_F size;
        //    size.width = player.hurtbox.right - player.hurtbox.left;
        //    size.height = player.hurtbox.bottom - player.hurtbox.top;
        //    D2D1_RECT_F destRect = D2D1::RectF(player.hurtbox.left, player.hurtbox.top,
        //        size.width + player.hurtbox.left, size.height + player.hurtbox.top);
        //    pRenderTarget->DrawBitmap(playerHurtBoxBitmap, destRect);
        //}

        // Get the bitmap for the current player weapon frame from the map
        ID2D1Bitmap* playerWeaponFrameBitmap = pBitmaps[player.weaponFileName];

        // Draw the player weapon frame
        if (playerWeaponFrameBitmap)
        {
            D2D1_SIZE_F size = playerWeaponFrameBitmap->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(player.weaponXPosition, player.weaponYPosition,
                (size.width * scalerX / 10) + player.weaponXPosition, (size.height * scalerY / 10) + player.weaponYPosition);
            pRenderTarget->DrawBitmap(playerWeaponFrameBitmap, destRect);
        }

        HRESULT hr = S_OK;

        // Create DirectWrite factory and text format for rendering HP & MP counter
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

        // Align the text to the right
        if (SUCCEEDED(hr)) {
            hr = pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
        }

        // Create the brush for text
        if (SUCCEEDED(hr)) {
            hr = pRenderTarget->CreateSolidColorBrush(
                D2D1::ColorF(D2D1::ColorF::White),
                &pBrush
            );
        }

        // Get the bitmap for the player HP Bar Shell from the map
        ID2D1Bitmap* playerHPBarShell = pBitmaps[hpBarShell];

        // Draw the player HP Bar Shell
        if (playerHPBarShell)
        {
            D2D1_SIZE_F size = playerHPBarShell->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(sysScreenX - (3 * size.width) - 10, 0 + 10,
                sysScreenX - 10, 10 + (3 * size.height));
            pRenderTarget->DrawBitmap(playerHPBarShell, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

            // Draw HP total
            WCHAR buffer[128];
            swprintf_s(buffer, L"%.0f/%.0f", player.HP, player.maxHP);
            D2D1_RECT_F layoutRect = D2D1::RectF(sysScreenX - (3 * size.width) - 200, 24, sysScreenX - (3 * size.width) - 15, size.height / 2 + 38);
            pRenderTarget->DrawText(
                buffer,
                wcslen(buffer),
                pTextFormat,
                layoutRect,
                pBrush
            );
        }

        // Get the bitmap for the player HP Bar Filling from the map
        ID2D1Bitmap* playerHPBarFilling = pBitmaps[hpBarFilling];

        // Draw the player HP Bar Filling
        if (playerHPBarFilling)
        {
            D2D1_SIZE_F size = playerHPBarFilling->GetSize();

            // Calculate the width of the HP bar filling based on player's current HP
            double hpRatio = player.HP / player.maxHP;
            unsigned int hpBarWidth = size.width * hpRatio;

            // Set up the source rectangle from the bitmap of the HP bar filling
            D2D1_RECT_F srcRect = D2D1::RectF(0, 0, hpBarWidth, size.height);

            // Store variables for Bar width and height
            double w = ((size.width) - 13) * scalerX;
            double h = size.height * scalerX;

            // Set up the destination rectangle for the HP bar filling
            D2D1_RECT_F destRect = D2D1::RectF(sysScreenX - w, 10 * scalerY,
                sysScreenX - w + (scalerX * hpBarWidth), 10 + (h));

            pRenderTarget->DrawBitmap(playerHPBarFilling, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
        }

        // Get the bitmap for the player MP Bar Shell from the map
        ID2D1Bitmap* playerMPBarShell = pBitmaps[mpBarShell];

        // Draw the player MP Bar Shell
        if (playerMPBarShell)
        {
            D2D1_SIZE_F size = playerMPBarShell->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(sysScreenX - (3 * size.width) - 10, 10 + (3 * size.height),
                sysScreenX - 10, 10 + (6 * size.height));
            pRenderTarget->DrawBitmap(playerMPBarShell, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);

            // Draw MP total
            WCHAR buffer[128];
            swprintf_s(buffer, L"%.0f/%.0f", player.MP, player.maxMP);
            D2D1_RECT_F layoutRect = D2D1::RectF(sysScreenX - (3 * size.width) - 200, 78, sysScreenX - (3 * size.width) - 15, size.height + 300);
            pRenderTarget->DrawText(
                buffer,
                wcslen(buffer),
                pTextFormat,
                layoutRect,
                pBrush
            );
        }

        // Get the bitmap for the player MP Bar Filling from the map
        ID2D1Bitmap* playerMPBarFilling = pBitmaps[mpBarFilling];

        // Draw the player MP Bar Filling
        if (playerMPBarFilling)
        {
            D2D1_SIZE_F size = playerMPBarFilling->GetSize();

            // Calculate the width of the MP bar filling based on player's current MP
            double mpRatio = player.MP / player.maxMP;
            unsigned int mpBarWidth = size.width * mpRatio;

            // Set up the source rectangle from the bitmap of the MP bar filling
            D2D1_RECT_F srcRect = D2D1::RectF(0, 0, mpBarWidth, size.height);

            // Set up the destination rectangle for the MP bar filling
            D2D1_RECT_F destRect = D2D1::RectF(sysScreenX - (3 * size.width) - 13, 10 + (3 * size.height),
                sysScreenX - (3 * size.width) - 13 + (3 * mpBarWidth), 10 + (6 * size.height));

            pRenderTarget->DrawBitmap(playerMPBarFilling, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
        }

        // Get the bitmap for the player EXP Bar Shell from the map
        ID2D1Bitmap* playerEXPBarShell = pBitmaps[expBarShell];

        // Draw the player EXP Bar Shell
        if (playerEXPBarShell)
        {
            D2D1_SIZE_F size = playerEXPBarShell->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(sysScreenX - (3 * size.width) - 10, 122,
                sysScreenX - 10, 134);
            pRenderTarget->DrawBitmap(playerEXPBarShell, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
        }

        // Get the bitmap for the player EXP Bar Filling from the map
        ID2D1Bitmap* playerEXPBarFilling = pBitmaps[expBarFilling];

        // Draw the player EXP Bar Filling
        if (playerEXPBarFilling)
        {
            D2D1_SIZE_F size = playerEXPBarFilling->GetSize();

            // Calculate the width of the EXP bar filling based on player's current MP
            double expRatio = player.exp / player.levelup;
            unsigned int expBarWidth = size.width * expRatio;

            // Set up the source rectangle from the bitmap of the EXP bar filling
            D2D1_RECT_F srcRect = D2D1::RectF(0, 0, expBarWidth, size.height);

            // Set up the destination rectangle for the EXP bar filling
            D2D1_RECT_F destRect = D2D1::RectF(sysScreenX - (3 * size.width) - 13, 122,
                sysScreenX - (3 * size.width) - 13 + (3 * expBarWidth), 134);

            pRenderTarget->DrawBitmap(playerEXPBarFilling, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, srcRect);
        }

        // Get the bitmap for the player Skill Panes from the map
        ID2D1Bitmap* playerSkillPanes = pBitmaps[skillPanes];

        // Draw the player Skill Panes
        if (playerSkillPanes)
        {
            int offset = 20;
            D2D1_SIZE_F size = playerSkillPanes->GetSize();
            D2D1_RECT_F destRect = D2D1::RectF(offset, offset, offset + 4 * size.width, offset + 4 * size.height);
            pRenderTarget->DrawBitmap(playerSkillPanes, destRect, 1.0F, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
        }

        // Create DirectWrite factory and text format for rendering FPS counter
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

        //// Get the bitmap for the weapon hitbox from the map
        //ID2D1Bitmap* playerHitBoxBitmap = pBitmaps[playerHitBox];

        //// Draw the weapon hitbox frame
        //if (playerHitBoxBitmap && playerWeaponFrameBitmap)
        //{
        //    D2D1_SIZE_F size = playerWeaponFrameBitmap->GetSize();
        //    D2D1_RECT_F destRect = D2D1::RectF(player.weaponXPosition, player.weaponYPosition,
        //        size.width + player.weaponXPosition, size.height + player.weaponYPosition);
        //    pRenderTarget->DrawBitmap(playerHitBoxBitmap, destRect);
        //}

        //if (pTextFormat && pBrush)
        //{
        //    // Compute FPS if a quarter of a second or more has passed since last update
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

Object background;
std::vector<Object> spriteData;
Player player;
Enemy leafEnemy[10];
std::vector<Enemy> enemies;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
    /* initialize random seed: */
    srand(time(NULL));

    // Load all Sprites
    LoadSpriteData(spriteData);

    std::vector<bool> calendar(365, false);

    int i = 0;

    enemies.reserve(10);
    for (int i = 0; i < 10; i++)
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
        std::chrono::steady_clock::time_point currentFrameTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> elapsedTime = currentFrameTime - lastMoveTime;

        for (int i = 0; i < enemies.size(); i++)
        {
            if (enemies.at(i).framesWalked2 % 288 == 0 && (std::chrono::steady_clock::now() - enemies.at(i).hitStunStartTime) >= enemies.at(i).hitStunTime)
            {
                double leafXDir = ((rand() % 200)) - 100;
                leafXDir /= 100;
                double leafYDir = ((rand() % 200)) - 100;
                leafYDir /= 100;
                ApplyEnemyDirectionalInput(enemies.at(i), 2 * leafXDir, 2 * leafYDir);
            }
            else if ((std::chrono::steady_clock::now() - enemies.at(i).hitStunStartTime) >= enemies.at(i).hitStunTime)
            {
                ApplyEnemyDirectionalInput(enemies.at(i), enemies.at(i).lastXDirection2, enemies.at(i).lastYDirection2);
            }
        }

        double xDir, yDir;
        if (keys.space == false && player.isBasicAttacking == false)
        {
            GetDirectionalInput(xDir, yDir, keys.right, keys.left, keys.down, keys.up);
            if (keys.lShift == true)
            {
                xDir *= 2;
                yDir *= 2;
                player.walkAnimationInterval = std::chrono::nanoseconds(124999999);
            }
            else
            {
                player.walkAnimationInterval = std::chrono::nanoseconds(166666666);
            }
            ApplyPlayerDirectionalInput(player, elapsedTime, currentFrameTime, 3 * xDir, 3 * yDir);
        }

        else if (keys.space == true || player.isBasicAttacking == true)
        {
            player.BasicAttack(enemies);
        }

        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        OnRender(hWnd, spriteData, player, enemies);

        // Increment frame count for FPS computation
        frameCount++;

        EndPaint(hWnd, &ps);

        // Invalidate the window rectangle to cause WM_PAINT message to be generated
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