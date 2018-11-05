#ifndef ISOCPP2_PASSAGEDATA_H
#define ISOCPP2_PASSAGEDATA_H

#include "dds/dds.hpp"

#include "PassageData.h"
#include "PassageDataSplDcps.h"

#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/DataRepresentation.hpp"

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<PassageData::PassageMessage>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "userID";
    }

    static const char *getTypeName()
    {
        return "PassageData::PassageMessage";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"PassageData\"><Struct name=\"PassageMessage\"><Member name=\"userID\">",
"<Long/></Member><Member name=\"index\"><Long/></Member><Member name=\"title\"><String/></Member><Member name=\"pic_url\">",
"<String/></Member><Member name=\"content\"><String/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(324);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __PassageData_PassageMessage__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __PassageData_PassageMessage__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<PassageData::PassageMessage>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<PassageData::PassageMessage>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(PassageData::PassageMessage)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<PassageData::NameService>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "userID";
    }

    static const char *getTypeName()
    {
        return "PassageData::NameService";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"PassageData\"><TypeDef name=\"nameType\"><String length=\"32\"/>",
"</TypeDef><Struct name=\"NameService\"><Member name=\"userID\"><Long/></Member><Member name=\"name\">",
"<Type name=\"nameType\"/></Member></Struct></Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(271);
        for (int i = 0; i < 3; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __PassageData_NameService__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __PassageData_NameService__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<PassageData::NameService>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<PassageData::NameService>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(PassageData::NameService)

namespace org { namespace opensplice { namespace topic {
template <>
class TopicTraits<PassageData::NamedMessage>
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::OSPL_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "userID";
    }

    static const char *getTypeName()
    {
        return "PassageData::NamedMessage";
    }

    static std::string getDescriptor()
    {
        const char *elements[] = {
            "<MetaData version=\"1.0.0\"><Module name=\"PassageData\"><TypeDef name=\"nameType\"><String length=\"32\"/>",
"</TypeDef><Struct name=\"NamedMessage\"><Member name=\"userID\"><Long/></Member><Member name=\"userName\">",
"<Type name=\"nameType\"/></Member><Member name=\"index\"><Long/></Member><Member name=\"title\"><String/>",
"</Member><Member name=\"pic_url\"><String/></Member><Member name=\"content\"><String/></Member></Struct>",
"</Module></MetaData>"
        };
        std::string descriptor;
        descriptor.reserve(442);
        for (int i = 0; i < 5; i++) {
            descriptor.append(elements[i]);
        }

        return descriptor;
    }

    static copyInFunction getCopyIn()
    {
        return (copyInFunction) __PassageData_NamedMessage__copyIn;
    }

    static copyOutFunction getCopyOut()
    {
        return (copyOutFunction) __PassageData_NamedMessage__copyOut;
    }
};
}}}

namespace dds { namespace topic {
template <>
struct topic_type_name<PassageData::NamedMessage>
{
    static std::string value()
    {
        return org::opensplice::topic::TopicTraits<PassageData::NamedMessage>::getTypeName();
    }
};
}}

REGISTER_TOPIC_TYPE(PassageData::NamedMessage)

#endif /* ISOCPP2_PASSAGEDATA_H */
