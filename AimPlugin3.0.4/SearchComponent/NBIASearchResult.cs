//L  
// Copyright Northwestern University
// Copyright Stanford University (ATB 1.0 and ATS 1.0)
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.

using ClearCanvas.Common.Utilities;
namespace SearchComponent
{
    [Cloneable]
	public class NBIASearchResult
	{
		public NBIASearchResult()
		{}

		public Patient Patient = new Patient();
		public Study Study = new Study();
		public Series Series = new Series();
        public Image Image = new Image();
		public TrialDataProvenance TrialDataProvenance = new TrialDataProvenance();
		public ClinicalTrialProtocol ClinicalTrialProtocol = new ClinicalTrialProtocol();
        public ClinicalTrialSite ClinicalTrialSite = new ClinicalTrialSite();

	}
}
