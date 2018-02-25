/* AUTOMATICALLY GENERATED, DO NOT MODIFY */

/*
 * deallocation functions for schema-defined QAPI types
 *
 * Copyright IBM, Corp. 2011
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *  Michael Roth      <mdroth@linux.vnet.ibm.com>
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 *
 */

#include "qapi/dealloc-visitor.h"
#include "qapi-types.h"
#include "qapi-visit.h"

void qapi_free_DummyForceArrays(DummyForceArrays *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_DummyForceArrays(v, NULL, &obj, NULL);
    visit_free(v);
}

const char *const QType_lookup[] = {
    "none",
    "qnull",
    "qint",
    "qstring",
    "qdict",
    "qlist",
    "qfloat",
    "qbool",
    NULL,
};

const char *const QapiErrorClass_lookup[] = {
    "GenericError",
    "CommandNotFound",
    "DeviceEncrypted",
    "DeviceNotActive",
    "DeviceNotFound",
    "KVMMissingCap",
    NULL,
};

void qapi_free_X86CPUFeatureWordInfo(X86CPUFeatureWordInfo *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_X86CPUFeatureWordInfo(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_X86CPUFeatureWordInfoList(X86CPUFeatureWordInfoList *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_X86CPUFeatureWordInfoList(v, NULL, &obj, NULL);
    visit_free(v);
}

const char *const X86CPURegister32_lookup[] = {
    "EAX",
    "EBX",
    "ECX",
    "EDX",
    "ESP",
    "EBP",
    "ESI",
    "EDI",
    NULL,
};

void qapi_free_anyList(anyList *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_anyList(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_boolList(boolList *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_boolList(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_int16List(int16List *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_int16List(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_int32List(int32List *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_int32List(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_int64List(int64List *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_int64List(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_int8List(int8List *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_int8List(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_intList(intList *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_intList(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_numberList(numberList *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_numberList(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_sizeList(sizeList *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_sizeList(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_strList(strList *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_strList(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_uint16List(uint16List *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_uint16List(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_uint32List(uint32List *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_uint32List(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_uint64List(uint64List *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_uint64List(v, NULL, &obj, NULL);
    visit_free(v);
}

void qapi_free_uint8List(uint8List *obj)
{
    Visitor *v;

    if (!obj) {
        return;
    }

    v = qapi_dealloc_visitor_new();
    visit_type_uint8List(v, NULL, &obj, NULL);
    visit_free(v);
}
