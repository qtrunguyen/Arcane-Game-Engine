using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Runtime.Serialization;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.IO;
using System.Text;

namespace ArcaneEditor.GameProject
{
    class NewProject : ViewModelBase
    {
        private string _name = "NewProject";
        public string ProjectName
        {
            get => _name;
            set
            {
                if (_name != value) _name = value;
                OnPropertyChanged(nameof(ProjectName));
            }
        }

        private string _projectPath = $@"{Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)}\ArcaneProject\";

        public string ProjectPath
        {
            get => _projectPath;
            set
            {
                if (_projectPath != value)
                {
                    _projectPath = value;
                    OnPropertyChanged(nameof(ProjectPath));
                }
            }
        }

        private bool _isValid;

        public bool IsValid
        {
            get => _isValid;
            set
            {
                if (_isValid != value)
                {
                    _isValid = value;
                    OnPropertyChanged(nameof(IsValid));
                }
            }
        }
        //private bool ValidateProjectPath()
        //{
        //    var path = ProjectPath;
        //    if (!Path.EndsInDirectorySeparator(path)) path += @"\";
        //    path += $@"{ProjectName}\";
        //}
    }
}
