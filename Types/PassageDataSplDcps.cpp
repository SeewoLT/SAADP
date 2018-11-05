#include "PassageData_DCPS.hpp"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__PassageData_PassageMessage__copyIn(
    c_base base,
    const class ::PassageData::PassageMessage *from,
    struct _PassageData_PassageMessage *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->userID = (c_long)from->userID_;
    to->index = (c_long)from->index_;
#ifdef OSPL_BOUNDS_CHECK
        to->title = c_stringNew_s(base, from->title_.c_str());
        if(to->title == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
#else
            to->title = c_stringNew_s(base, from->title_.c_str());
            if(to->title == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
#ifdef OSPL_BOUNDS_CHECK
        to->pic_url = c_stringNew_s(base, from->pic_url_.c_str());
        if(to->pic_url == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
#else
            to->pic_url = c_stringNew_s(base, from->pic_url_.c_str());
            if(to->pic_url == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
#ifdef OSPL_BOUNDS_CHECK
        to->content = c_stringNew_s(base, from->content_.c_str());
        if(to->content == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
#else
            to->content = c_stringNew_s(base, from->content_.c_str());
            if(to->content == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
    return result;
}

v_copyin_result
__PassageData_NameService__copyIn(
    c_base base,
    const class ::PassageData::NameService *from,
    struct _PassageData_NameService *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->userID = (c_long)from->userID_;
#ifdef OSPL_BOUNDS_CHECK
        if(((unsigned int)from->name_.length())) <= 32){
            to->name = c_stringNew_s(base, from->name_.c_str());
            if(to->name == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
        } else {
            OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'PassageData::NameService.name' of type 'C_STRING<32>' is out of range.");
            result = V_COPYIN_RESULT_INVALID;
        }
#else
            to->name = c_stringNew_s(base, from->name_.c_str());
            if(to->name == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
    return result;
}

v_copyin_result
__PassageData_NamedMessage__copyIn(
    c_base base,
    const class ::PassageData::NamedMessage *from,
    struct _PassageData_NamedMessage *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->userID = (c_long)from->userID_;
#ifdef OSPL_BOUNDS_CHECK
        if(((unsigned int)from->userName_.length())) <= 32){
            to->userName = c_stringNew_s(base, from->userName_.c_str());
            if(to->userName == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
        } else {
            OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'PassageData::NamedMessage.userName' of type 'C_STRING<32>' is out of range.");
            result = V_COPYIN_RESULT_INVALID;
        }
#else
            to->userName = c_stringNew_s(base, from->userName_.c_str());
            if(to->userName == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
    to->index = (c_long)from->index_;
#ifdef OSPL_BOUNDS_CHECK
        to->title = c_stringNew_s(base, from->title_.c_str());
        if(to->title == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
#else
            to->title = c_stringNew_s(base, from->title_.c_str());
            if(to->title == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
#ifdef OSPL_BOUNDS_CHECK
        to->pic_url = c_stringNew_s(base, from->pic_url_.c_str());
        if(to->pic_url == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
#else
            to->pic_url = c_stringNew_s(base, from->pic_url_.c_str());
            if(to->pic_url == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
#ifdef OSPL_BOUNDS_CHECK
        to->content = c_stringNew_s(base, from->content_.c_str());
        if(to->content == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
#else
            to->content = c_stringNew_s(base, from->content_.c_str());
            if(to->content == NULL) {
                result = V_COPYIN_RESULT_OUT_OF_MEMORY;
            }
#endif
    return result;
}

void
__PassageData_PassageMessage__copyOut(
    const void *_from,
    void *_to)
{
    const struct _PassageData_PassageMessage *from = (const struct _PassageData_PassageMessage *)_from;
    class ::PassageData::PassageMessage *to = (class ::PassageData::PassageMessage *)_to;
    to->userID((int32_t)from->userID);
    to->index((int32_t)from->index);
    to->title(from->title ? from->title : "");
    to->pic_url(from->pic_url ? from->pic_url : "");
    to->content(from->content ? from->content : "");
}

void
__PassageData_NameService__copyOut(
    const void *_from,
    void *_to)
{
    const struct _PassageData_NameService *from = (const struct _PassageData_NameService *)_from;
    class ::PassageData::NameService *to = (class ::PassageData::NameService *)_to;
    to->userID((int32_t)from->userID);
    to->name(from->name ? from->name : "");
}

void
__PassageData_NamedMessage__copyOut(
    const void *_from,
    void *_to)
{
    const struct _PassageData_NamedMessage *from = (const struct _PassageData_NamedMessage *)_from;
    class ::PassageData::NamedMessage *to = (class ::PassageData::NamedMessage *)_to;
    to->userID((int32_t)from->userID);
    to->userName(from->userName ? from->userName : "");
    to->index((int32_t)from->index);
    to->title(from->title ? from->title : "");
    to->pic_url(from->pic_url ? from->pic_url : "");
    to->content(from->content ? from->content : "");
}

