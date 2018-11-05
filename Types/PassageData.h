#ifndef _PASSAGEDATA_H_
#define _PASSAGEDATA_H_

#include <dds/core/ddscore.hpp>

namespace PassageData
{
    const int32_t MAX_NAME = 32L;

    typedef std::string nameType;

    class PassageMessage OSPL_DDS_FINAL
    {
    public:
        int32_t userID_;
        int32_t index_;
        std::string title_;
        std::string pic_url_;
        std::string content_;

    public:
        PassageMessage() :
                userID_(0),
                index_(0) {}

        explicit PassageMessage(
            int32_t userID,
            int32_t index,
            const std::string& title,
            const std::string& pic_url,
            const std::string& content) : 
                userID_(userID),
                index_(index),
                title_(title),
                pic_url_(pic_url),
                content_(content) {}

        PassageMessage(const PassageMessage &_other) : 
                userID_(_other.userID_),
                index_(_other.index_),
                title_(_other.title_),
                pic_url_(_other.pic_url_),
                content_(_other.content_) {}

#ifdef OSPL_DDS_CXX11
        PassageMessage(PassageMessage &&_other) : 
                userID_(::std::move(_other.userID_)),
                index_(::std::move(_other.index_)),
                title_(::std::move(_other.title_)),
                pic_url_(::std::move(_other.pic_url_)),
                content_(::std::move(_other.content_)) {}

        PassageMessage& operator=(PassageMessage &&_other)
        {
            if (this != &_other) {
                userID_ = ::std::move(_other.userID_);
                index_ = ::std::move(_other.index_);
                title_ = ::std::move(_other.title_);
                pic_url_ = ::std::move(_other.pic_url_);
                content_ = ::std::move(_other.content_);
            }
            return *this;
        }
#endif

        PassageMessage& operator=(const PassageMessage &_other)
        {
            if (this != &_other) {
                userID_ = _other.userID_;
                index_ = _other.index_;
                title_ = _other.title_;
                pic_url_ = _other.pic_url_;
                content_ = _other.content_;
            }
            return *this;
        }

        bool operator==(const PassageMessage& _other) const
        {
            return userID_ == _other.userID_ &&
                index_ == _other.index_ &&
                title_ == _other.title_ &&
                pic_url_ == _other.pic_url_ &&
                content_ == _other.content_;
        }

        bool operator!=(const PassageMessage& _other) const
        {
            return !(*this == _other);
        }

        int32_t userID() const { return this->userID_; }
        int32_t& userID() { return this->userID_; }
        void userID(int32_t _val_) { this->userID_ = _val_; }
        int32_t index() const { return this->index_; }
        int32_t& index() { return this->index_; }
        void index(int32_t _val_) { this->index_ = _val_; }
        const std::string& title() const { return this->title_; }
        std::string& title() { return this->title_; }
        void title(const std::string& _val_) { this->title_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void title(std::string&& _val_) { this->title_ = _val_; }
#endif
        const std::string& pic_url() const { return this->pic_url_; }
        std::string& pic_url() { return this->pic_url_; }
        void pic_url(const std::string& _val_) { this->pic_url_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void pic_url(std::string&& _val_) { this->pic_url_ = _val_; }
#endif
        const std::string& content() const { return this->content_; }
        std::string& content() { return this->content_; }
        void content(const std::string& _val_) { this->content_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void content(std::string&& _val_) { this->content_ = _val_; }
#endif
    };

    class NameService OSPL_DDS_FINAL
    {
    public:
        int32_t userID_;
        PassageData::nameType name_;

    public:
        NameService() :
                userID_(0) {}

        explicit NameService(
            int32_t userID,
            const PassageData::nameType& name) : 
                userID_(userID),
                name_(name) {}

        NameService(const NameService &_other) : 
                userID_(_other.userID_),
                name_(_other.name_) {}

#ifdef OSPL_DDS_CXX11
        NameService(NameService &&_other) : 
                userID_(::std::move(_other.userID_)),
                name_(::std::move(_other.name_)) {}

        NameService& operator=(NameService &&_other)
        {
            if (this != &_other) {
                userID_ = ::std::move(_other.userID_);
                name_ = ::std::move(_other.name_);
            }
            return *this;
        }
#endif

        NameService& operator=(const NameService &_other)
        {
            if (this != &_other) {
                userID_ = _other.userID_;
                name_ = _other.name_;
            }
            return *this;
        }

        bool operator==(const NameService& _other) const
        {
            return userID_ == _other.userID_ &&
                name_ == _other.name_;
        }

        bool operator!=(const NameService& _other) const
        {
            return !(*this == _other);
        }

        int32_t userID() const { return this->userID_; }
        int32_t& userID() { return this->userID_; }
        void userID(int32_t _val_) { this->userID_ = _val_; }
        const PassageData::nameType& name() const { return this->name_; }
        PassageData::nameType& name() { return this->name_; }
        void name(const PassageData::nameType& _val_) { this->name_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void name(PassageData::nameType&& _val_) { this->name_ = _val_; }
#endif
    };

    class NamedMessage OSPL_DDS_FINAL
    {
    public:
        int32_t userID_;
        PassageData::nameType userName_;
        int32_t index_;
        std::string title_;
        std::string pic_url_;
        std::string content_;

    public:
        NamedMessage() :
                userID_(0),
                index_(0) {}

        explicit NamedMessage(
            int32_t userID,
            const PassageData::nameType& userName,
            int32_t index,
            const std::string& title,
            const std::string& pic_url,
            const std::string& content) : 
                userID_(userID),
                userName_(userName),
                index_(index),
                title_(title),
                pic_url_(pic_url),
                content_(content) {}

        NamedMessage(const NamedMessage &_other) : 
                userID_(_other.userID_),
                userName_(_other.userName_),
                index_(_other.index_),
                title_(_other.title_),
                pic_url_(_other.pic_url_),
                content_(_other.content_) {}

#ifdef OSPL_DDS_CXX11
        NamedMessage(NamedMessage &&_other) : 
                userID_(::std::move(_other.userID_)),
                userName_(::std::move(_other.userName_)),
                index_(::std::move(_other.index_)),
                title_(::std::move(_other.title_)),
                pic_url_(::std::move(_other.pic_url_)),
                content_(::std::move(_other.content_)) {}

        NamedMessage& operator=(NamedMessage &&_other)
        {
            if (this != &_other) {
                userID_ = ::std::move(_other.userID_);
                userName_ = ::std::move(_other.userName_);
                index_ = ::std::move(_other.index_);
                title_ = ::std::move(_other.title_);
                pic_url_ = ::std::move(_other.pic_url_);
                content_ = ::std::move(_other.content_);
            }
            return *this;
        }
#endif

        NamedMessage& operator=(const NamedMessage &_other)
        {
            if (this != &_other) {
                userID_ = _other.userID_;
                userName_ = _other.userName_;
                index_ = _other.index_;
                title_ = _other.title_;
                pic_url_ = _other.pic_url_;
                content_ = _other.content_;
            }
            return *this;
        }

        bool operator==(const NamedMessage& _other) const
        {
            return userID_ == _other.userID_ &&
                userName_ == _other.userName_ &&
                index_ == _other.index_ &&
                title_ == _other.title_ &&
                pic_url_ == _other.pic_url_ &&
                content_ == _other.content_;
        }

        bool operator!=(const NamedMessage& _other) const
        {
            return !(*this == _other);
        }

        int32_t userID() const { return this->userID_; }
        int32_t& userID() { return this->userID_; }
        void userID(int32_t _val_) { this->userID_ = _val_; }
        const PassageData::nameType& userName() const { return this->userName_; }
        PassageData::nameType& userName() { return this->userName_; }
        void userName(const PassageData::nameType& _val_) { this->userName_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void userName(PassageData::nameType&& _val_) { this->userName_ = _val_; }
#endif
        int32_t index() const { return this->index_; }
        int32_t& index() { return this->index_; }
        void index(int32_t _val_) { this->index_ = _val_; }
        const std::string& title() const { return this->title_; }
        std::string& title() { return this->title_; }
        void title(const std::string& _val_) { this->title_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void title(std::string&& _val_) { this->title_ = _val_; }
#endif
        const std::string& pic_url() const { return this->pic_url_; }
        std::string& pic_url() { return this->pic_url_; }
        void pic_url(const std::string& _val_) { this->pic_url_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void pic_url(std::string&& _val_) { this->pic_url_ = _val_; }
#endif
        const std::string& content() const { return this->content_; }
        std::string& content() { return this->content_; }
        void content(const std::string& _val_) { this->content_ = _val_; }
#ifdef OSPL_DDS_CXX11
        void content(std::string&& _val_) { this->content_ = _val_; }
#endif
    };

}

#endif /* _PASSAGEDATA_H_ */
