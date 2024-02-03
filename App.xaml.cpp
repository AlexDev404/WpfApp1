using namespace System;
using namespace System::Diagnostics;
using namespace System::Windows;
using namespace System::Windows::Markup;
using namespace System::Resources;
using namespace System::Xml;
using namespace System::Windows::Controls;
// using namespace WpfApp1;
//#include "main.cpp"

namespace WpfApp1 {


    public ref class Bootup {
    private:
        FrameworkElement^ dynamicWindow;
    public:
        void OnLoaded(Object^ sender, RoutedEventArgs^ e) {
            Button^ myButton = dynamic_cast<Button^>(dynamicWindow->FindName("testControl"));

            if (myButton != nullptr) {
                // Connect event handler to the Button's Click event
                myButton->Click += gcnew RoutedEventHandler(&WpfApp1::Bootup::OnButtonClick);
            }
            // Handle the Loaded event
            // This is just an example, replace it with your actual code
            Trace::WriteLine("XAML loaded successfully!");
            MessageBox::Show("XAML loaded successfully!");
            // Create a new instance of Window
           // Window^ dynamicWindow = gcnew Window();
            //dynamicWindow->Show();

        }
        static void OnButtonClick(Object^ sender, RoutedEventArgs^ e) {
            // Handle the Button's Click event
            MessageBox::Show("Button Clicked!");
        }
        void AttachLoadedHandler(FrameworkElement^ frameworkElement) {
            // Assign dynamicWindow to its correct value
            this->dynamicWindow = frameworkElement;
            // Attach the event handler
            frameworkElement->Loaded += gcnew RoutedEventHandler(this, &WpfApp1::Bootup::OnLoaded);
        }
    };

    /// <summary>
    /// App
    /// </summary>
    public ref class App : Application {
    private:
        /// <summary>
        /// InitializeComponent
        /// </summary>

    public:
        void InitializeComponent() {
            // Load the resource manager
            ResourceManager^ rm = gcnew ResourceManager("Resource", GetType()->Assembly);

            // Get the XAML content as a string
            String^ xamlContent = static_cast<String^>(rm->GetObject("MainWindow"));
            Trace::WriteLine(xamlContent->ToString());
             
            // Create an instance of your App class
            // WpfApp1::App^ appInstance = gcnew WpfApp1::App();
            // Create XAML object writer settings
            Xaml::XamlObjectWriterSettings^ settings = gcnew Xaml::XamlObjectWriterSettings();
            settings->RootObjectInstance = this->ToString();
            Trace::WriteLine(this->ToString());
            // Load XAML content using XamlLoader
            // Object^ rootObject = XamlReader::Load(XmlReader::Create(gcnew System::IO::StringReader(xamlContent)));
            System::IO::StringReader^ xc = gcnew System::IO::StringReader(xamlContent);
            XmlReader^ xmlTextReader = XmlReader::Create(xc);
           
            /*Xaml::XamlXmlReader^ xamlReader = gcnew Xaml::XamlXmlReader(xmlTextReader);

            Trace::WriteLine(xamlReader->ToString());
            // Create a XAML object writer with settings
            Xaml::XamlObjectWriter^ objectWriter = gcnew Xaml::XamlObjectWriter(xamlReader->SchemaContext, settings);
            Trace::WriteLine(xamlReader->IsEof);

            // Load XAML content into the XamlObjectWriter
            Xaml::XamlObjectReader^ objectReader = gcnew Xaml::XamlObjectReader(objectWriter->Result);
            
            Trace::WriteLine(objectReader->Namespace);
            Trace::WriteLine(xmlTextReader);*/
            Object^ rootObject = XamlReader::Load(xmlTextReader);
            // Optionally, you can use the rootObject as needed
            // Set the StartupUri to the loaded XAML content
            // this->StartupUri = gcnew System::Uri("MainWindow.xaml", System::UriKind::Relative); // Use a dummy URI
            Trace::WriteLine("XAML Root Object: " + rootObject);
            // Check if the root object is a FrameworkElement
            FrameworkElement^ frameworkElement = dynamic_cast<FrameworkElement^>(rootObject);
            if (frameworkElement != nullptr) {
                Trace::WriteLine(frameworkElement->Visibility);
                frameworkElement->Visibility = System::Windows::Visibility::Visible; // Make this visible to finish the loading process
                frameworkElement->BeginInit();
                Trace::WriteLine("Moving to bootup... " + frameworkElement->IsLoaded);
                Trace::WriteLine("Moving to bootup... " + frameworkElement);
                frameworkElement->EndInit();
                Trace::WriteLine("Moving to bootup... " + frameworkElement->IsLoaded);
                Trace::WriteLine("Moving to bootup... " + frameworkElement->IsInitialized);


                // Attach the event handler using the add method
                WpfApp1::Bootup^ bootupInstance = gcnew WpfApp1::Bootup;
                bootupInstance->AttachLoadedHandler(frameworkElement);
                //frameworkElement->Loaded += gcnew RoutedEventHandler(gcnew WpfApp1::Bootup(), &WpfApp1::Bootup::OnLoaded);
                // Add other code connections...
            }
        }
       
        /// <summary>
        /// Application Entry Point.
        /// </summary>
        static void Main() {
            WpfApp1::App^ app = gcnew WpfApp1::App();
            app->InitializeComponent();
            app->Run();
        }
    };

}

