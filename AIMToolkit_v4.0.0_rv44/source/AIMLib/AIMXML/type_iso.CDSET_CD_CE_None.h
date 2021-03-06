/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_CD_CE_None
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_CD_CE_None

#include "type_iso.CCOLL_CD_CE_None.h"


namespace AIMXML
{

namespace iso
{	

class CDSET_CD_CE_None : public ::AIMXML::iso::CCOLL_CD_CE_None
{
public:
	AIMXML_EXPORT CDSET_CD_CE_None(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CDSET_CD_CE_None(CDSET_CD_CE_None const& init);
	void operator=(CDSET_CD_CE_None const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CDSET_CD_CE_None); }
	MemberElement<iso::CCD_CE_None, _altova_mi_iso_altova_CDSET_CD_CE_None_altova_item> item;
	struct item { typedef Iterator<iso::CCD_CE_None> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CDSET_CD_CE_None
