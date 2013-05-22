//L  
// Copyright Northwestern University
// Copyright Stanford University (ATB 1.0 and ATS 1.0)
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

using System;
using ClearCanvas.Common;

namespace AIM.Annotation
{
	[ExtensionPoint]
	public sealed class AimAnnotationExtensionPoint : ExtensionPoint<IAimAnnotationExtension>
	{
	}

	public interface IAimAnnotationExtension
	{
		AimAnnotationComponent Component { set; }
		string ButtonText { get; }
		void OnButtonClick(object sender, EventArgs e);
	}
}
