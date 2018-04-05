 AIM XNAT on ClearCanvas
 ====

 This integration can make modifying AIM more easily. We want to reconstruct the origin environment when AIM was created.

 This repository combines 3 github repos listed below.

 1. [NCIP/annotation-and-image-markup][AIM]
 2. [ClearCanvas/ClearCanvas][CC]
 3. [ClearCanvas/ReferencedAssemblies][CCRef]

We use [AimPlugin 4.5][AIMv4.5] to combine with [ClearCanvas 13.2][CC] using Visual Studio 2015.

## How to compile

Since we have used submodules and symbolic links, we should clone it by a sequence of commands.

Launch a elevated command prompt (with administrator rights) and type the following commands:

```shell
git clone https://github.com/j3soon/annotation-and-image-markup.git aim-xnat-cc
cd aim-xnat-cc
git submodule update --init --recursive
cd source_cc
git config --local core.symlinks true
git reset HEAD --hard
cd ..
```

Open the file `aim-xnat-cc\source_cc\ImageViewer\ImageViewer.sln` and set `ClearCanvas.Desktop.Executable` as the start up project.

Now, we can compile the entire solution directly just by clicking the debug button.

> The logs can bee seen in `aim-xnat-cc\source_cc\Desktop\Executable\bin\Debug\logs\ClearCanvas.Workstation.log`

## Modifications made

1. Folder hierarchy.

   The final folder (github repo) hierarchy is shown below.

   ```
   Root dir
   │ [annotation-and-image-markup.git]
   │
   ├─ReferencedAssemblies
   │   [ReferencedAssemblies.git]
   │
   └─source_cc
       [ClearCanvas.git]
       ReferencedAssemblies (Symbolic Link) <<===>> ..\ReferencedAssemblies
   ```

   > The hierarchy clues are from [AIM's .csproj files][AIMproj] and [ClearCanvas's Readme][CCReadme]. We use the following command to generate the symbolic link: `path\to\source_cc>mklink /D ReferencedAssemblies ..\ReferencedAssemblies`

2. Connect AIMPlugin4.5 to ClearCanvas

   - Add AIM plugins and their WinForms projects to your ImageViewer solution file.
   - Make Desktop.Executable project dependent on the newly added plugins.
   - Build Desktop.Executable. During an initial build, there may be errors related to visibility of some of the ClearCanvas classes. Make the classes in question public and build again.

   > The steps are exactly the same as the steps mentioned in [AIMPlugin4.5's readme][AIMv4.5Readme].
   Note that there shouldn't be any `.dll` files in the same directory as `ClearCanvas.Desktop.Executable.exe` (`Copy Local` should be False), otherwise, there will be dll conflicts.

3. Additional DLLs

   After the first 2 steps, it should work now. However, in [DicomViewer-13.2.19401.1661-x64][CCbin]'s and [AIM on ClearCanvas® Workstation][AIMbin]'s plugin folder, there are some dlls that aren't included by the 2 steps above. So we also add them to the plugin folder using [PostBuild_dist.proj](source_cc\Desktop\Executable\PostBuild_dist.proj).

   - In ClearCanvas but not in compiled:
     ```
     ClearCanvas.ImageViewer.Shreds.dll
     ```
   - In AIM on ClearCanvas but not in compiled:
     ```
     AIMLib.dll
     AIMLib.NET.dll
     AIMLibModel.NET.dll
     AimTmplUtil1923.dll
     AimTmplUtilV1Rv23V2Rv13.dll
     TCGA.dll
     TCGA.View.WinForms.dll
     xerces-c_3_1.dll
     ```

4. Release mode

   When compiling in release mode, errors will occur when clicking the `AIM Data Service 2.0` tab.

   It seems to be the typo in [AimDataService.View.WinForms.csproj
](AimPlugin4.5/AimDataService/View/WinForms/AimDataService.View.WinForms.csproj).

   ```xml
   <!--<PlatformTarget>x86</PlatformTarget>-->
   <PlatformTarget>AnyCPU</PlatformTarget>
   ```

## Untested problems

1. x86 and x64 dll dependencies

   The `x86` parts in [PostBuild_dist.proj](source_cc\Desktop\Executable\PostBuild_dist.proj) may be changed in some circumstances.

   ```xml
   <SharedPluginFiles Include="$(ProjectDir)..\..\..\AIMToolkit_v4.1.0_rv44\source\xercesc-3.1\x86\bin\xerces-c_3_1.dll" />
   <SharedPluginFiles Include="$(ProjectDir..\..\..\AimPlugin4.5\AIMReferences\(Configuration)\4.0\x86\AIMLib.dll" />
   <SharedPluginFiles Include="$(ProjectDir..\..\..\AimPlugin4.5\AIMReferences\(Configuration)\4.0\x86\AIMLib.NET.dll" />
   <SharedPluginFiles Include="$(ProjectDir..\..\..\AimPlugin4.5\AIMReferences\(Configuration)\4.0\x86\AIMLibModel.NET.dll" />
   ```

2. Namespace ambiguity in [SegmentationSerializer](AimPlugin4.5\Segmentation\SegmentationSerializer.cs) and [SegmentationDocumentIod](AimPlugin4.5\Segmentation\DICOM\SegmentationDocumentIod.cs).

   ```cs
   //Added to avoid namespace ambiguity.
   using FrameOfReferenceModuleIod =  ClearCanvas.Dicom.Iod.Modules. FrameOfReferenceModuleIod;
   ```

3. Empty implementations to make TCGA compatible in [TcgaSessionManager](AimPlugin4.5/TCGA/TcgaSessionManager.cs).

   ```cs
   // The 4 entries below are added to implement the new ISessionManager.
   public void InvalidateSession()
   {
   }

   public void TerminateSession()
   {
   }

   public SessionStatus SessionStatus { get; }
   public eventEventHandler<SessionStatusChangedEventArgs>SessionStatusChanged;
   ```

4. Warning in log file.

   ```
   WARN  - No audit sink extensions found - Auditing will be disabled for the remainder of the session.
   ```

Pull requests are welcome.

[AIM]: https://github.com/NCIP/annotation-and-image-markup
[CC]: https://github.com/ClearCanvas/ClearCanvas
[CCRef]: https://github.com/ClearCanvas/ReferencedAssemblies
[AIMv4.5]: https://github.com/NCIP/annotation-and-image-markup/tree/master/AimPlugin4.5
[AIMv4.5Readme]: https://github.com/NCIP/annotation-and-image-markup/blob/master/AimPlugin4.5/readme.txt
[AIMproj]: https://github.com/NCIP/annotation-and-image-markup/blob/e3f3340aae3f59c3676cf0c1077c890ef47dda6d/AimPlugin4.5/XnatWebBrowser/XnatWebBrowser.csproj#L135
[CCReadme]: https://github.com/ClearCanvas/ClearCanvas/blob/master/README.md#how-to-build-using-github-for-windows
[CCbin]: https://github.com/ClearCanvas/ClearCanvas/releases
[AIMbin]: https://wiki.nci.nih.gov/display/AIM/Annotation+and+Image+Markup+-+AIM

 Welcome to the Annotation and Image Markup Project!
===================================================
Annotation and image markup  is an Open Source project that provides the functionalities to propose and create a standard means of adding information and knowledge to an image in a clinical environment, so that image content can be easily and automatically searched. 
AIM provides a solution to the following imaging challenges:
  * No agreed upon syntax for annotation and markup
  * No agreed upon semantics to describe annotations
  * No standard format (for example, DICOM, XML, HL7) for annotations and markup

The AIM project includes the following.
   * The AIM Model captures the descriptive information for an image with user-generated graphical symbols placed on the image into a single common information source.
   * The AIM Template Service is a web service application that makes it possible for you to upload (publish) and download AIM templates created using an AIM tool such as AIM Template Builder.
   * The AIM Template Builder is a Java application that allows you to build templates that are compatible with the AIM Model. Templates are a set of well-defined questions and answer choices that facilitate collecting information for a study. The AIM Template Builder has replaced the AIM Template Manager.
   * AIM on ClearCanvas Workstation is a reference implementation of the AIM Model. AIM on ClearCanvas Workstation demonstrat

It is written in C, C++, Visual C++, Java using XML and ClearCanvas Workstation.
The goal of Annotation and Image Markup Project is to develop a mechanism, for modeling, capturing, and serializing image annotation and markup data that can be adopted as a standard by the medical imaging community. 
  
AIM is distributed under the BSD 3-Clause License.
Please see the NOTICE and LICENSE files for details.

You will find more details about AIM in the following links:
  * [Community Wiki] (https://wiki.nci.nih.gov/x/z4X3Ag)
  * Issue Tracker 
   * [AIM - Information Model(AIM)] (https://tracker.nci.nih.gov/browse/AIM)
   * [AIM - Enterprise Service(AIMES)] (https://tracker.nci.nih.gov/browse/AIMES)
   * [ AIM - Workstation (AIMWS)] (https://tracker.nci.nih.gov/browse/AIMWS)
  * [Code Repository] (https://github.com/NCIP/annotation-and-image-markup)
  * [View Website] (http://imaging.fsm.northwestern.edu/templates/web)

Please join us in further developing and improving Annotation and Markup(AIM).
