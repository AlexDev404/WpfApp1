using namespace System;
using namespace System::Diagnostics;
using namespace System::Windows;
using namespace System::Windows::Automation;
using namespace System::Windows::Controls;
using namespace System::Windows::Controls::Primitives;
using namespace System::Windows::Data;
using namespace System::Windows::Documents;
using namespace System::Windows::Ink;
using namespace System::Windows::Input;
using namespace System::Windows::Markup;
using namespace System::Windows::Media;
using namespace System::Windows::Media::Animation;
using namespace System::Windows::Media::Effects;
using namespace System::Windows::Media::Imaging;
using namespace System::Windows::Media::Media3D;
using namespace System::Windows::Media::TextFormatting;
using namespace System::Windows::Navigation;
using namespace System::Windows::Shapes;
using namespace System::Windows::Shell;

#include "App.xaml.cpp"
using namespace WpfApp1;

namespace WpfApp1 {


    /// <summary>
    /// App
    /// </summary>
    public ref class MainWindow : Window, IComponentConnector {
    private: bool _contentLoaded;
        /// <summary>
        /// InitializeComponent
        /// </summary>
    public: MainWindow() {
        InitializeComponent();
    }
        virtual void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System::Uri^ resourceLocater = gcnew System::Uri("/WpfApp1;component/mainwindow.xaml", System::UriKind::Relative);
            Application::LoadComponent(this, resourceLocater);

        }

        /// <summary>
        /// Application Connection Point.
        /// </summary>
        virtual void Connect(int connectionId, System::Object^ target) {
            WpfApp1::App^ app = gcnew WpfApp1::App();
            this->_contentLoaded = true;
        }
    };
}

