// TODO: use WinMain

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    Chimera::Application* app = Chimera::CreateApplication();
    app->Run();
    delete app;
}
