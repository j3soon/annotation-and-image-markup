//L  
// Copyright Northwestern University
// Copyright Stanford University (ATB 1.0 and ATS 1.0)
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

using System;
using System.Windows.Forms;

using ClearCanvas.Common.Utilities;

namespace AIM.Annotation.View.WinForms.Template
{
	public partial class ConfidenceControl : UserControl
	{
		public event EventHandler ConfidenceChanged;

		public ConfidenceControl()
		{
			InitializeComponent();
		}

		public double Value
		{
			get { return (double)_upDownConfidence.Value; }
			set { _upDownConfidence.Value = (decimal)value; }
		}

		private void OnConfidenceValueChanged(object sender, EventArgs e)
		{
			EventsHelper.Fire(ConfidenceChanged, this, EventArgs.Empty);
		}
	}
}
