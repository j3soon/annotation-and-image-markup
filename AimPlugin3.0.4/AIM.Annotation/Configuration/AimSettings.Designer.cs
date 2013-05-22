//L  
// Copyright Northwestern University
// Copyright Stanford University (ATB 1.0 and ATS 1.0)
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

namespace AIM.Annotation.Configuration {
    
    
    [global::System.Runtime.CompilerServices.CompilerGeneratedAttribute()]
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.VisualStudio.Editors.SettingsDesigner.SettingsSingleFileGenerator", "9.0.0.0")]
    public sealed partial class AimSettings : global::System.Configuration.ApplicationSettingsBase {
        
        private static AimSettings defaultInstance = ((AimSettings)(global::System.Configuration.ApplicationSettingsBase.Synchronized(new AimSettings())));
        
        public static AimSettings Default {
            get {
                return defaultInstance;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("False")]
        public bool SendNewXmlAnnotationsToGrid {
            get {
                return ((bool)(this["SendNewXmlAnnotationsToGrid"]));
            }
            set {
                this["SendNewXmlAnnotationsToGrid"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("True")]
        public bool StoreXmlAnnotationsLocally {
            get {
                return ((bool)(this["StoreXmlAnnotationsLocally"]));
            }
            set {
                this["StoreXmlAnnotationsLocally"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("True")]
        public bool StoreXmlInMyDocuments {
            get {
                return ((bool)(this["StoreXmlInMyDocuments"]));
            }
            set {
                this["StoreXmlInMyDocuments"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("")]
        public string LocalAnnotationsFolder {
            get {
                return ((string)(this["LocalAnnotationsFolder"]));
            }
            set {
                this["LocalAnnotationsFolder"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("")]
        public string UserName {
            get {
                return ((string)(this["UserName"]));
            }
            set {
                this["UserName"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("")]
        public string UserRoleInTrial {
            get {
                return ((string)(this["UserRoleInTrial"]));
            }
            set {
                this["UserRoleInTrial"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("")]
        public string UserLoginName {
            get {
                return ((string)(this["UserLoginName"]));
            }
            set {
                this["UserLoginName"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("-1")]
        public int UserNumberWitinRoleOfClinicalTrial {
            get {
                return ((int)(this["UserNumberWitinRoleOfClinicalTrial"]));
            }
            set {
                this["UserNumberWitinRoleOfClinicalTrial"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("True")]
        public bool RequireUserInfo {
            get {
                return ((bool)(this["RequireUserInfo"]));
            }
            set {
                this["RequireUserInfo"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("True")]
        public bool RequireMarkupInAnnotation {
            get {
                return ((bool)(this["RequireMarkupInAnnotation"]));
            }
            set {
                this["RequireMarkupInAnnotation"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("")]
        public string LocalTemplatesFolder {
            get {
                return ((string)(this["LocalTemplatesFolder"]));
            }
            set {
                this["LocalTemplatesFolder"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public global::GeneralUtilities.Collections.XmlSerializableStringDictionary SendQueuesNames {
            get {
                return ((global::GeneralUtilities.Collections.XmlSerializableStringDictionary)(this["SendQueuesNames"]));
            }
            set {
                this["SendQueuesNames"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("Yellow")]
        public global::System.Drawing.Color DefaultMarkupColor {
            get {
                return ((global::System.Drawing.Color)(this["DefaultMarkupColor"]));
            }
            set {
                this["DefaultMarkupColor"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("False")]
        public bool UseRandomDefaultMarkupColor {
            get {
                return ((bool)(this["UseRandomDefaultMarkupColor"]));
            }
            set {
                this["UseRandomDefaultMarkupColor"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("")]
        public string SelectedTemplatePathName {
            get {
                return ((string)(this["SelectedTemplatePathName"]));
            }
            set {
                this["SelectedTemplatePathName"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("https://secure01.cci.emory.edu")]
        public string BaseUrl {
            get {
                return ((string)(this["BaseUrl"]));
            }
            set {
                this["BaseUrl"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("8443")]
        public string Port {
            get {
                return ((string)(this["Port"]));
            }
            set {
                this["Port"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("False")]
        public bool AllowUntrustedCertificates {
            get {
                return ((bool)(this["AllowUntrustedCertificates"]));
            }
            set {
                this["AllowUntrustedCertificates"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("")]
        public string TargetUrl {
            get {
                return ((string)(this["TargetUrl"]));
            }
            set {
                this["TargetUrl"] = value;
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public global::GeneralUtilities.Collections.XmlSerializableStringDictionary Parameters {
            get {
                return ((global::GeneralUtilities.Collections.XmlSerializableStringDictionary)(this["Parameters"]));
            }
            set {
                this["Parameters"] = value;
            }
        }
        
        [global::System.Configuration.ApplicationScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("https://wiki.nci.nih.gov/display/AIM/AIM+on+ClearCanvas+Workstation+User%27s+Guid" +
            "e")]
        public string AimUserGuidePath {
            get {
                return ((string)(this["AimUserGuidePath"]));
            }
        }
        
        [global::System.Configuration.UserScopedSettingAttribute()]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.Configuration.DefaultSettingValueAttribute("\r\n                    <dictionary />\r\n                ")]
        public global::GeneralUtilities.Collections.XmlSerializableStringToColorDictionary LoginNameMarkupColors {
            get {
                return ((global::GeneralUtilities.Collections.XmlSerializableStringToColorDictionary)(this["LoginNameMarkupColors"]));
            }
            set {
                this["LoginNameMarkupColors"] = value;
            }
        }
    }
}
