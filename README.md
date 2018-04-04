 AIM XNAT on ClearCanvas
 ====

 This integration can make modifying AIM more easily. We want to reconstruct the origin environment when AIM was created.

 This repository combines 3 github repos listed below.

 1. [NCIP/annotation-and-image-markup][AIM]
 2. [ClearCanvas/ClearCanvas][CC]
 3. [ClearCanvas/ReferencedAssemblies][CCRef]

We use [AimPlugin 4.5][AIMv4.5] to combine with [ClearCanvas 13.2][CC] using Visual Studio 2015.

## Modifications

1.  Folder hierarchy.

    The final folder (github repo) hierarchy is shown below.

    ```
    Root dir
    │  [annotation-and-image-markup.git]
    │
    ├─ReferencedAssemblies
    │    [ReferencedAssemblies.git]
    │
    └─source_cc
        [ClearCanvas.git]
        ReferencedAssemblies (Symbolic Link) <<===>> ..\ReferencedAssemblies
    ```

    > The hierarchy clues are from [AIM's .csproj files][AIMproj] and [ClearCavas's Readme][CCReadme]. We use the following command instead 
    `path\to\source_cc>mklink /D ReferencedAssemblies ..\ReferencedAssemblies`.

2. Connect AIMPlugin4.5 to ClearCanvas

    - Add AIM plugins and their WinForms projects to your ImageViewer solution file.
    - Make Desktop.Executable project dependent on the newly added plugins.
    - Build Desktop.Executable. During an initial build, there may be errors related to visibility of some of the ClearCanvas classes. Make the classes in question public and build again.

    > The steps are almost the same as the steps in [AIMPlugin4.5's readme][AIMv4.5Readme].
    Note that there shouldn't be any `.dll` files in the same directory as `ClearCanvas.Desktop.Executable.exe`. (`Copy Local` should be false)

3. Additional DLLs

    After the first 2 steps, it should work now. However, in [DicomViewer-13.2.19401.1661-x64][CCbin]'s and [AIM on ClearCanvas® Workstation][AIMbin]'s plugin folder, there are some dlls that aren't included by the 2 steps above. So we also add them to the plugin folder.

Now, we can compile it directly just by one click after cloning this repo. Please submit a pull request if we missed something.

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
  
AIM is distrubuted under the BSD 3-Clause License.
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
