#ifndef PASSAGEDATASPLTYPES_H
#define PASSAGEDATASPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "PassageData_DCPS.hpp"


extern c_metaObject __PassageData_PassageData__load (c_base base);

extern c_metaObject __PassageData_nameType__load (c_base base);
typedef c_string _PassageData_nameType;

extern const char *PassageData_PassageMessage_metaDescriptor[];
extern const int PassageData_PassageMessage_metaDescriptorArrLength;
extern const int PassageData_PassageMessage_metaDescriptorLength;
extern c_metaObject __PassageData_PassageMessage__load (c_base base);
struct _PassageData_PassageMessage ;
extern  v_copyin_result __PassageData_PassageMessage__copyIn(c_base base, const class PassageData::PassageMessage *from, struct _PassageData_PassageMessage *to);
extern  void __PassageData_PassageMessage__copyOut(const void *_from, void *_to);
struct _PassageData_PassageMessage {
    c_long userID;
    c_long index;
    c_string title;
    c_string pic_url;
    c_string content;
};

extern const char *PassageData_NameService_metaDescriptor[];
extern const int PassageData_NameService_metaDescriptorArrLength;
extern const int PassageData_NameService_metaDescriptorLength;
extern c_metaObject __PassageData_NameService__load (c_base base);
struct _PassageData_NameService ;
extern  v_copyin_result __PassageData_NameService__copyIn(c_base base, const class PassageData::NameService *from, struct _PassageData_NameService *to);
extern  void __PassageData_NameService__copyOut(const void *_from, void *_to);
struct _PassageData_NameService {
    c_long userID;
    _PassageData_nameType name;
};

extern const char *PassageData_NamedMessage_metaDescriptor[];
extern const int PassageData_NamedMessage_metaDescriptorArrLength;
extern const int PassageData_NamedMessage_metaDescriptorLength;
extern c_metaObject __PassageData_NamedMessage__load (c_base base);
struct _PassageData_NamedMessage ;
extern  v_copyin_result __PassageData_NamedMessage__copyIn(c_base base, const class PassageData::NamedMessage *from, struct _PassageData_NamedMessage *to);
extern  void __PassageData_NamedMessage__copyOut(const void *_from, void *_to);
struct _PassageData_NamedMessage {
    c_long userID;
    _PassageData_nameType userName;
    c_long index;
    c_string title;
    c_string pic_url;
    c_string content;
};

#undef OS_API
#endif
