#include "pch.h"
// #include "App.xaml.cpp"

// using namespace System;
// using namespace System::Windows::Forms;
using namespace System;
using namespace System::Windows;
using namespace System::Diagnostics;
using namespace System::Windows::Markup;
using namespace System::IO;

[STAThread]
int main() {
    // Connect event handlers or perform other actions as needed
    // Window^ dynamicWindow
    
    /*
    // Read and parse app.xaml
    System::String^ basePath = System::AppDomain::CurrentDomain->BaseDirectory;
    System::String^ fullPath = System::IO::Path::Combine(basePath, "App.xaml");

    System::IO::Stream^ xamlStream = gcnew FileStream(fullPath, FileMode::Open, FileAccess::Read);
    
    // Create an instance of WpfApp1.App
    //WpfApp1::App^ appInstance = gcnew WpfApp1::App();

    


    // Create XamlObjectWriterSettings and set the root object instance
    //Xaml::XamlObjectWriterSettings^ settings = gcnew Xaml::XamlObjectWriterSettings();
    //settings->RootObjectInstance = appInstance;
    Object^ rootObject = XamlReader::Load(xamlStream);
  

    // Ensure the rootObject is an Application
    if (dynamic_cast<WpfApp1::App^>(rootObject) != nullptr)
    {
        // Cast to Application and run
        WpfApp1::App^ app = dynamic_cast<WpfApp1::App^>(rootObject);
  //      app->InitializeComponent();  // Optionally initialize the application
        app->Run();
    }
    else
    {
        // Handle error: app.xaml does not define a valid Application
        Trace::WriteLine("Error: 'app.xaml' does not define a valid Application.");
        return -1;
    }
    */
    
	/*
	WpfApp1::App^ mainWindow = gcnew WpfApp1::App();
	System::String^ basePath = System::AppDomain::CurrentDomain->BaseDirectory;
	System::String^ fullPath = System::IO::Path::Combine(basePath, "App.xaml");
	System::Uri^ StartupUri = gcnew System::Uri(fullPath, System::UriKind::Absolute);
	Trace::WriteLine("StartupUri Path: " + fullPath->ToString());
	mainWindow->InitializeComponent();
	mainWindow->Run();
	*/

	//WpfApp1::App::Main();
	//WpfApp1::App^ app = gcnew WpfApp1::App();
	// app->Main();
	return 0;
}