//L  
// Copyright Northwestern University
// Copyright Stanford University (ATB 1.0 and ATS 1.0)
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

namespace SearchComponent {
    
    
    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "9.0.0.0")]
    public sealed partial class SearchSettings : global::System.Configuration.ApplicationSettingsBase {
        
        private static SearchSettings defaultInstance = ((SearchSettings)(global::System.Configuration.ApplicationSettingsBase.Synchronized(new SearchSettings())));
        
        public static SearchSettings Default {
            get {
                return defaultInstance;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("<?xml version=\"1.0\" encoding=\"utf-16\"?>\r\n<ArrayOfString xmlns:xsi=\"http://www.w3." +
            "org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" />")]
        public global::System.Collections.Specialized.StringCollection AimSearchHiddenColumns {
            get {
                return ((global::System.Collections.Specialized.StringCollection)(this["AimSearchHiddenColumns"]));
            }
            set {
                this["AimSearchHiddenColumns"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("<?xml version=\"1.0\" encoding=\"utf-16\"?>\r\n<ArrayOfString xmlns:xsi=\"http://www.w3." +
            "org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" />")]
        public global::System.Collections.Specialized.StringCollection NbiaSearchHiddenColumns {
            get {
                return ((global::System.Collections.Specialized.StringCollection)(this["NbiaSearchHiddenColumns"]));
            }
            set {
                this["NbiaSearchHiddenColumns"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("http://imaging.nci.nih.gov/wsrf/services/cagrid/NCIACoreService")]
        public string NBIADataServiceUrl {
            get {
                return ((string)(this["NBIADataServiceUrl"]));
            }
            set {
                this["NBIADataServiceUrl"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public global::System.Collections.Specialized.StringCollection NBIADataServiceUrlList {
            get {
                return ((global::System.Collections.Specialized.StringCollection)(this["NBIADataServiceUrlList"]));
            }
            set {
                this["NBIADataServiceUrlList"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("http://imaging.nci.nih.gov/wsrf/services/cagrid/TransferServiceContext")]
        public string NBIADataServiceTransferUrl {
            get {
                return ((string)(this["NBIADataServiceTransferUrl"]));
            }
            set {
                this["NBIADataServiceTransferUrl"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public global::System.Collections.Specialized.StringCollection NBIADataServiceTransferUrlList {
            get {
                return ((global::System.Collections.Specialized.StringCollection)(this["NBIADataServiceTransferUrlList"]));
            }
            set {
                this["NBIADataServiceTransferUrlList"] = value;
            }
        }
    }
}
