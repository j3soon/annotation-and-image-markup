/*
 *
 *  Copyright (C) 2000-2012, OFFIS e.V.
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *
 *  This software and supporting documentation were developed by
 *
 *    OFFIS e.V.
 *    R&D Division Health
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *
 *  Module:  dcmsr
 *
 *  Author:  Joerg Riesmeier
 *
 *  Purpose:
 *    classes: DSRTextTreeNode
 *
 */


#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */

#include "dcmtk/dcmsr/dsrtypes.h"
#include "dcmtk/dcmsr/dsrtextn.h"
#include "dcmtk/dcmsr/dsrstrvl.h"
#include "dcmtk/dcmsr/dsrxmld.h"


DSRTextTreeNode::DSRTextTreeNode(const E_RelationshipType relationshipType)
  : DSRDocumentTreeNode(relationshipType, VT_Text),
    DSRStringValue()
{
}


DSRTextTreeNode::DSRTextTreeNode(const E_RelationshipType relationshipType,
                                 const OFString &textValue,
                                 const OFBool check)
  : DSRDocumentTreeNode(relationshipType, VT_Text),
    DSRStringValue(textValue, check)
{
}


DSRTextTreeNode::~DSRTextTreeNode()
{
}


void DSRTextTreeNode::clear()
{
    DSRDocumentTreeNode::clear();
    DSRStringValue::clear();
}


OFBool DSRTextTreeNode::isValid() const
{
    /* ConceptNameCodeSequence required */
    /* tbd: there might be an issue with checking extended characters! */
    return DSRDocumentTreeNode::isValid() && getConceptName().isValid() && checkCurrentValue().good();
}


OFBool DSRTextTreeNode::isShort(const size_t /*flags*/) const
{
    return (getValue().length() <= 40);
}


OFCondition DSRTextTreeNode::print(STD_NAMESPACE ostream &stream,
                                   const size_t flags) const
{
    OFCondition result = DSRDocumentTreeNode::print(stream, flags);
    if (result.good())
    {
        DCMSR_PRINT_ANSI_ESCAPE_CODE(DCMSR_ANSI_ESCAPE_CODE_DELIMITER)
        stream << "=";
        DCMSR_PRINT_ANSI_ESCAPE_CODE(DCMSR_ANSI_ESCAPE_CODE_ITEM_VALUE)
        if (flags & PF_shortenLongItemValues)
            DSRStringValue::print(stream, 30);     // text output is limited to 30 characters
        else
            DSRStringValue::print(stream);
    }
    return result;
}


OFCondition DSRTextTreeNode::writeXML(STD_NAMESPACE ostream &stream,
                                      const size_t flags) const
{
    OFCondition result = EC_Normal;
    writeXMLItemStart(stream, flags);
    result = DSRDocumentTreeNode::writeXML(stream, flags);
    writeStringValueToXML(stream, getValue(), "value", (flags & XF_writeEmptyTags) > 0);
    writeXMLItemEnd(stream, flags);
    return result;
}


OFCondition DSRTextTreeNode::readContentItem(DcmItem &dataset)
{
    /* read TextValue */
    return DSRStringValue::read(dataset, DCM_TextValue);
}


OFCondition DSRTextTreeNode::writeContentItem(DcmItem &dataset) const
{
    /* write TextValue */
    return DSRStringValue::write(dataset, DCM_TextValue);
}


OFCondition DSRTextTreeNode::readXMLContentItem(const DSRXMLDocument &doc,
                                                DSRXMLCursor cursor)
{
    /* retrieve value from XML element "value" */
    return DSRStringValue::readXML(doc, doc.getNamedNode(cursor.gotoChild(), "value"), OFTrue /*encoding*/);
}


OFCondition DSRTextTreeNode::renderHTMLContentItem(STD_NAMESPACE ostream &docStream,
                                                   STD_NAMESPACE ostream & /*annexStream*/,
                                                   const size_t /*nestingLevel*/,
                                                   size_t & /*annexNumber*/,
                                                   const size_t flags) const
{
    OFString htmlString;
    /* render ConceptName */
    OFCondition result = renderHTMLConceptName(docStream, flags);
    /* render TextValue */
    if (flags & HF_renderItemInline)
        docStream << "\"" << convertToHTMLString(getValue(), htmlString, flags) << "\"" << OFendl;
    else
        docStream << convertToHTMLString(getValue(), htmlString, flags, OFTrue /*newlineAllowed*/) << OFendl;
    return result;
}


OFCondition DSRTextTreeNode::checkValue(const OFString &textValue) const
{
    /* first, make sure that the mandatory value is non-empty */
    OFCondition result = DSRStringValue::checkValue(textValue);
    /* then, check whether the passed value is valid */
    if (result.good())
        result = DcmUnlimitedText::checkStringValue(textValue);
    return result;
}
