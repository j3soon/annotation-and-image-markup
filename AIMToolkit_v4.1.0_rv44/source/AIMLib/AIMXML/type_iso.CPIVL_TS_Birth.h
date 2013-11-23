/*
Copyright (c) 2008-2013, Northwestern University
All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 
  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
 
  Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
 
  Neither the name of the Northwestern University nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CPIVL_TS_Birth
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CPIVL_TS_Birth

#include "type_iso.CQSET_TS_Birth.h"


namespace AIMXML
{

namespace iso
{	

class CPIVL_TS_Birth : public ::AIMXML::iso::CQSET_TS_Birth
{
public:
	AIMXML_EXPORT CPIVL_TS_Birth(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CPIVL_TS_Birth(CPIVL_TS_Birth const& init);
	void operator=(CPIVL_TS_Birth const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CPIVL_TS_Birth); }
	MemberAttribute<string_type,_altova_mi_iso_altova_CPIVL_TS_Birth_altova_alignment, 0, 15> alignment;	// alignment CCalendarCycle

	MemberAttribute<bool,_altova_mi_iso_altova_CPIVL_TS_Birth_altova_institutionSpecified, 0, 0> institutionSpecified;	// institutionSpecified Cboolean
	MemberElement<iso::CIVL_TS_Birth, _altova_mi_iso_altova_CPIVL_TS_Birth_altova_phase> phase;
	struct phase { typedef Iterator<iso::CIVL_TS_Birth> iterator; };
	MemberElement<iso::CPQ, _altova_mi_iso_altova_CPIVL_TS_Birth_altova_period> period;
	struct period { typedef Iterator<iso::CPQ> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CPIVL_TS_Birth