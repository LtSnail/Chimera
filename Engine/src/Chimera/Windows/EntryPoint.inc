// TODO: use WinMain

int main()
{
    Chimera::Log::Init();
    
    CH_CORE_WARN("Core Log!");
    CH_INFO("Client Log!");

    Chimera::Application* app = Chimera::CreateApplication();
    app->Run();
    delete app;
}
