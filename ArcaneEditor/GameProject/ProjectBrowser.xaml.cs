using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace ArcaneEditor.GameProject
{
    /// <summary>
    /// Interaction logic for ProjectBrowser.xaml
    /// </summary>
    public partial class ProjectBrowser : Window
    {
        public ProjectBrowser()
        {
            InitializeComponent();
        }
        private void OnToggleButtonClicked(object sender, RoutedEventArgs e)
        {
            if (sender == openProjectButton)
            {
                if (newProjectButton.IsChecked == true)
                {
                    newProjectButton.IsChecked = false;
                    browserContent.Margin = new Thickness(0);
                }
                openProjectButton.IsChecked = true;
            }
            else
            {
                if (openProjectButton.IsChecked == true)
                {
                    openProjectButton.IsChecked = false;
                    browserContent.Margin = new Thickness(-800, 0, 0, 0);
                }
                newProjectButton.IsChecked = true;
            }
        }
    }
}
