/*L
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
L*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CEquipment
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CEquipment



namespace AIMXML
{

class CEquipment : public TypeBase
{
public:
	AIMXML_EXPORT CEquipment(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CEquipment(CEquipment const& init);
	void operator=(CEquipment const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CEquipment); }
	MemberElement<iso::CST, _altova_mi_altova_CEquipment_altova_manufacturerName> manufacturerName;
	struct manufacturerName { typedef Iterator<iso::CST> iterator; };
	MemberElement<iso::CST, _altova_mi_altova_CEquipment_altova_manufacturerModelName> manufacturerModelName;
	struct manufacturerModelName { typedef Iterator<iso::CST> iterator; };
	MemberElement<iso::CST, _altova_mi_altova_CEquipment_altova_deviceSerialNumber> deviceSerialNumber;
	struct deviceSerialNumber { typedef Iterator<iso::CST> iterator; };
	MemberElement<iso::CST, _altova_mi_altova_CEquipment_altova_softwareVersion> softwareVersion;
	struct softwareVersion { typedef Iterator<iso::CST> iterator; };
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CEquipment
