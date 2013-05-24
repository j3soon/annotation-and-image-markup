/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
L*/

#pragma once
#ifndef _AIMLib_DicomImageReferenceEntity_Class_
#define _AIMLib_DicomImageReferenceEntity_Class_

namespace aim_lib
{
	class AIMLIB_API DicomImageReferenceEntity : public ImageReferenceEntity
	{
	public:
		DicomImageReferenceEntity();
		DicomImageReferenceEntity(const DicomImageReferenceEntity& imageReference);
		virtual ~DicomImageReferenceEntity();
		virtual DicomImageReferenceEntity* Clone() const;

		virtual ImageReferenceEntityType GetImageReferenceEntityType() const;

		const ImageStudy& GetImageStudy() const;
		void SetImageStudy(const ImageStudy& study);

	private:
		ImageStudy _imageStudy;
	};
}
#endif // _AIMLib_DicomImageReferenceEntity_Class_
