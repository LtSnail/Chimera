int main()
{
    printf("Chimera Engine");

    Chimera::Application* app = Chimera::CreateApplication();
    app->Run();
    delete app;
}
