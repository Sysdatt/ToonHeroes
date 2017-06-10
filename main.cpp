#include "main.h"
#include "AppDelegate.h"
#include "cocos2d.h"

USING_NS_CC;

HINSTANCE g_hInstance;

#include "Core.h"

Core* Core::instance = NULL;


int WINAPI _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	g_hInstance = hInstance;

    // create the application instance
    AppDelegate app;
    return Application::getInstance()->run();
}
