/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
L*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CtaskContextEntityCollectionType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CtaskContextEntityCollectionType



namespace AIMXML
{

class CtaskContextEntityCollectionType : public TypeBase
{
public:
	AIMXML_EXPORT CtaskContextEntityCollectionType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CtaskContextEntityCollectionType(CtaskContextEntityCollectionType const& init);
	void operator=(CtaskContextEntityCollectionType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CtaskContextEntityCollectionType); }
	MemberElement<CTaskContextEntity, _altova_mi_altova_CtaskContextEntityCollectionType_altova_TaskContextEntity> TaskContextEntity;
	struct TaskContextEntity { typedef Iterator<CTaskContextEntity> iterator; };
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CtaskContextEntityCollectionType
