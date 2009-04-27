//
// Generated file, do not edit! Created by opp_msgc 4.0 from Messages.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "Messages_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(NlmeMsg);

NlmeMsg::NlmeMsg(const char *name, int kind) : cPacket(name,kind)
{
}

NlmeMsg::NlmeMsg(const NlmeMsg& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

NlmeMsg::~NlmeMsg()
{
}

NlmeMsg& NlmeMsg::operator=(const NlmeMsg& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void NlmeMsg::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void NlmeMsg::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class NlmeMsgDescriptor : public cClassDescriptor
{
  public:
    NlmeMsgDescriptor();
    virtual ~NlmeMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmeMsgDescriptor);

NlmeMsgDescriptor::NlmeMsgDescriptor() : cClassDescriptor("NlmeMsg", "cPacket")
{
}

NlmeMsgDescriptor::~NlmeMsgDescriptor()
{
}

bool NlmeMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmeMsg *>(obj)!=NULL;
}

const char *NlmeMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmeMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int NlmeMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return 0;
    }
}

const char *NlmeMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *NlmeMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *NlmeMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NlmeMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmeMsg *pp = (NlmeMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmeMsgDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmeMsg *pp = (NlmeMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

bool NlmeMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmeMsg *pp = (NlmeMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NlmeMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmeMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmeMsg *pp = (NlmeMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NlmeNetworkFormation_request);

NlmeNetworkFormation_request::NlmeNetworkFormation_request(const char *name, int kind) : NlmeMsg(name,kind)
{
    this->ScanChannels_var = 0;
    this->ScanDuration_var = 0;
    this->BeaconOrder_var = 0;
    this->SuperframeOrder_var = 0;
    this->PANId_var = 0;
    this->BatteryLifeExtension_var = 0;
}

NlmeNetworkFormation_request::NlmeNetworkFormation_request(const NlmeNetworkFormation_request& other) : NlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

NlmeNetworkFormation_request::~NlmeNetworkFormation_request()
{
}

NlmeNetworkFormation_request& NlmeNetworkFormation_request::operator=(const NlmeNetworkFormation_request& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    this->ScanChannels_var = other.ScanChannels_var;
    this->ScanDuration_var = other.ScanDuration_var;
    this->BeaconOrder_var = other.BeaconOrder_var;
    this->SuperframeOrder_var = other.SuperframeOrder_var;
    this->PANId_var = other.PANId_var;
    this->BatteryLifeExtension_var = other.BatteryLifeExtension_var;
    return *this;
}

void NlmeNetworkFormation_request::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
    doPacking(b,this->ScanChannels_var);
    doPacking(b,this->ScanDuration_var);
    doPacking(b,this->BeaconOrder_var);
    doPacking(b,this->SuperframeOrder_var);
    doPacking(b,this->PANId_var);
    doPacking(b,this->BatteryLifeExtension_var);
}

void NlmeNetworkFormation_request::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->ScanChannels_var);
    doUnpacking(b,this->ScanDuration_var);
    doUnpacking(b,this->BeaconOrder_var);
    doUnpacking(b,this->SuperframeOrder_var);
    doUnpacking(b,this->PANId_var);
    doUnpacking(b,this->BatteryLifeExtension_var);
}

unsigned int NlmeNetworkFormation_request::getScanChannels() const
{
    return ScanChannels_var;
}

void NlmeNetworkFormation_request::setScanChannels(unsigned int ScanChannels_var)
{
    this->ScanChannels_var = ScanChannels_var;
}

unsigned char NlmeNetworkFormation_request::getScanDuration() const
{
    return ScanDuration_var;
}

void NlmeNetworkFormation_request::setScanDuration(unsigned char ScanDuration_var)
{
    this->ScanDuration_var = ScanDuration_var;
}

unsigned char NlmeNetworkFormation_request::getBeaconOrder() const
{
    return BeaconOrder_var;
}

void NlmeNetworkFormation_request::setBeaconOrder(unsigned char BeaconOrder_var)
{
    this->BeaconOrder_var = BeaconOrder_var;
}

unsigned char NlmeNetworkFormation_request::getSuperframeOrder() const
{
    return SuperframeOrder_var;
}

void NlmeNetworkFormation_request::setSuperframeOrder(unsigned char SuperframeOrder_var)
{
    this->SuperframeOrder_var = SuperframeOrder_var;
}

unsigned short NlmeNetworkFormation_request::getPANId() const
{
    return PANId_var;
}

void NlmeNetworkFormation_request::setPANId(unsigned short PANId_var)
{
    this->PANId_var = PANId_var;
}

unsigned char NlmeNetworkFormation_request::getBatteryLifeExtension() const
{
    return BatteryLifeExtension_var;
}

void NlmeNetworkFormation_request::setBatteryLifeExtension(unsigned char BatteryLifeExtension_var)
{
    this->BatteryLifeExtension_var = BatteryLifeExtension_var;
}

class NlmeNetworkFormation_requestDescriptor : public cClassDescriptor
{
  public:
    NlmeNetworkFormation_requestDescriptor();
    virtual ~NlmeNetworkFormation_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmeNetworkFormation_requestDescriptor);

NlmeNetworkFormation_requestDescriptor::NlmeNetworkFormation_requestDescriptor() : cClassDescriptor("NlmeNetworkFormation_request", "NlmeMsg")
{
}

NlmeNetworkFormation_requestDescriptor::~NlmeNetworkFormation_requestDescriptor()
{
}

bool NlmeNetworkFormation_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmeNetworkFormation_request *>(obj)!=NULL;
}

const char *NlmeNetworkFormation_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmeNetworkFormation_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int NlmeNetworkFormation_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISEDITABLE;
        case 5: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *NlmeNetworkFormation_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "ScanChannels";
        case 1: return "ScanDuration";
        case 2: return "BeaconOrder";
        case 3: return "SuperframeOrder";
        case 4: return "PANId";
        case 5: return "BatteryLifeExtension";
        default: return NULL;
    }
}

const char *NlmeNetworkFormation_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned int";
        case 1: return "unsigned char";
        case 2: return "unsigned char";
        case 3: return "unsigned char";
        case 4: return "unsigned short";
        case 5: return "unsigned char";
        default: return NULL;
    }
}

const char *NlmeNetworkFormation_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NlmeNetworkFormation_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkFormation_request *pp = (NlmeNetworkFormation_request *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmeNetworkFormation_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkFormation_request *pp = (NlmeNetworkFormation_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getScanChannels(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getScanDuration(),resultbuf,bufsize); return true;
        case 2: ulong2string(pp->getBeaconOrder(),resultbuf,bufsize); return true;
        case 3: ulong2string(pp->getSuperframeOrder(),resultbuf,bufsize); return true;
        case 4: ulong2string(pp->getPANId(),resultbuf,bufsize); return true;
        case 5: ulong2string(pp->getBatteryLifeExtension(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool NlmeNetworkFormation_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkFormation_request *pp = (NlmeNetworkFormation_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setScanChannels(string2ulong(value)); return true;
        case 1: pp->setScanDuration(string2ulong(value)); return true;
        case 2: pp->setBeaconOrder(string2ulong(value)); return true;
        case 3: pp->setSuperframeOrder(string2ulong(value)); return true;
        case 4: pp->setPANId(string2ulong(value)); return true;
        case 5: pp->setBatteryLifeExtension(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NlmeNetworkFormation_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmeNetworkFormation_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkFormation_request *pp = (NlmeNetworkFormation_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NlmeNetworkFormation_confirm);

NlmeNetworkFormation_confirm::NlmeNetworkFormation_confirm(const char *name, int kind) : NlmeMsg(name,kind)
{
    this->status_var = 0;
}

NlmeNetworkFormation_confirm::NlmeNetworkFormation_confirm(const NlmeNetworkFormation_confirm& other) : NlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

NlmeNetworkFormation_confirm::~NlmeNetworkFormation_confirm()
{
}

NlmeNetworkFormation_confirm& NlmeNetworkFormation_confirm::operator=(const NlmeNetworkFormation_confirm& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    this->status_var = other.status_var;
    return *this;
}

void NlmeNetworkFormation_confirm::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
}

void NlmeNetworkFormation_confirm::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
}

unsigned char NlmeNetworkFormation_confirm::getStatus() const
{
    return status_var;
}

void NlmeNetworkFormation_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

class NlmeNetworkFormation_confirmDescriptor : public cClassDescriptor
{
  public:
    NlmeNetworkFormation_confirmDescriptor();
    virtual ~NlmeNetworkFormation_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmeNetworkFormation_confirmDescriptor);

NlmeNetworkFormation_confirmDescriptor::NlmeNetworkFormation_confirmDescriptor() : cClassDescriptor("NlmeNetworkFormation_confirm", "NlmeMsg")
{
}

NlmeNetworkFormation_confirmDescriptor::~NlmeNetworkFormation_confirmDescriptor()
{
}

bool NlmeNetworkFormation_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmeNetworkFormation_confirm *>(obj)!=NULL;
}

const char *NlmeNetworkFormation_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmeNetworkFormation_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int NlmeNetworkFormation_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *NlmeNetworkFormation_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        default: return NULL;
    }
}

const char *NlmeNetworkFormation_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        default: return NULL;
    }
}

const char *NlmeNetworkFormation_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NlmeNetworkFormation_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkFormation_confirm *pp = (NlmeNetworkFormation_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmeNetworkFormation_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkFormation_confirm *pp = (NlmeNetworkFormation_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool NlmeNetworkFormation_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkFormation_confirm *pp = (NlmeNetworkFormation_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NlmeNetworkFormation_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmeNetworkFormation_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkFormation_confirm *pp = (NlmeNetworkFormation_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NlmeNetworkDiscovery_request);

NlmeNetworkDiscovery_request::NlmeNetworkDiscovery_request(const char *name, int kind) : NlmeMsg(name,kind)
{
    this->ScanChannels_var = 0;
    this->ScanDuration_var = 0;
}

NlmeNetworkDiscovery_request::NlmeNetworkDiscovery_request(const NlmeNetworkDiscovery_request& other) : NlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

NlmeNetworkDiscovery_request::~NlmeNetworkDiscovery_request()
{
}

NlmeNetworkDiscovery_request& NlmeNetworkDiscovery_request::operator=(const NlmeNetworkDiscovery_request& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    this->ScanChannels_var = other.ScanChannels_var;
    this->ScanDuration_var = other.ScanDuration_var;
    return *this;
}

void NlmeNetworkDiscovery_request::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
    doPacking(b,this->ScanChannels_var);
    doPacking(b,this->ScanDuration_var);
}

void NlmeNetworkDiscovery_request::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->ScanChannels_var);
    doUnpacking(b,this->ScanDuration_var);
}

unsigned int NlmeNetworkDiscovery_request::getScanChannels() const
{
    return ScanChannels_var;
}

void NlmeNetworkDiscovery_request::setScanChannels(unsigned int ScanChannels_var)
{
    this->ScanChannels_var = ScanChannels_var;
}

unsigned char NlmeNetworkDiscovery_request::getScanDuration() const
{
    return ScanDuration_var;
}

void NlmeNetworkDiscovery_request::setScanDuration(unsigned char ScanDuration_var)
{
    this->ScanDuration_var = ScanDuration_var;
}

class NlmeNetworkDiscovery_requestDescriptor : public cClassDescriptor
{
  public:
    NlmeNetworkDiscovery_requestDescriptor();
    virtual ~NlmeNetworkDiscovery_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmeNetworkDiscovery_requestDescriptor);

NlmeNetworkDiscovery_requestDescriptor::NlmeNetworkDiscovery_requestDescriptor() : cClassDescriptor("NlmeNetworkDiscovery_request", "NlmeMsg")
{
}

NlmeNetworkDiscovery_requestDescriptor::~NlmeNetworkDiscovery_requestDescriptor()
{
}

bool NlmeNetworkDiscovery_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmeNetworkDiscovery_request *>(obj)!=NULL;
}

const char *NlmeNetworkDiscovery_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmeNetworkDiscovery_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int NlmeNetworkDiscovery_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *NlmeNetworkDiscovery_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "ScanChannels";
        case 1: return "ScanDuration";
        default: return NULL;
    }
}

const char *NlmeNetworkDiscovery_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned int";
        case 1: return "unsigned char";
        default: return NULL;
    }
}

const char *NlmeNetworkDiscovery_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NlmeNetworkDiscovery_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkDiscovery_request *pp = (NlmeNetworkDiscovery_request *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmeNetworkDiscovery_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkDiscovery_request *pp = (NlmeNetworkDiscovery_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getScanChannels(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getScanDuration(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool NlmeNetworkDiscovery_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkDiscovery_request *pp = (NlmeNetworkDiscovery_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setScanChannels(string2ulong(value)); return true;
        case 1: pp->setScanDuration(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NlmeNetworkDiscovery_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmeNetworkDiscovery_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkDiscovery_request *pp = (NlmeNetworkDiscovery_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NlmeNetworkDiscovery_confirm);

NlmeNetworkDiscovery_confirm::NlmeNetworkDiscovery_confirm(const char *name, int kind) : NlmeMsg(name,kind)
{
    this->networkCount_var = 0;
    NetworkDescriptorList_arraysize = 0;
    this->NetworkDescriptorList_var = 0;
    this->status_var = 0;
}

NlmeNetworkDiscovery_confirm::NlmeNetworkDiscovery_confirm(const NlmeNetworkDiscovery_confirm& other) : NlmeMsg()
{
    setName(other.getName());
    NetworkDescriptorList_arraysize = 0;
    this->NetworkDescriptorList_var = 0;
    operator=(other);
}

NlmeNetworkDiscovery_confirm::~NlmeNetworkDiscovery_confirm()
{
    delete [] NetworkDescriptorList_var;
}

NlmeNetworkDiscovery_confirm& NlmeNetworkDiscovery_confirm::operator=(const NlmeNetworkDiscovery_confirm& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    this->networkCount_var = other.networkCount_var;
    delete [] this->NetworkDescriptorList_var;
    this->NetworkDescriptorList_var = (other.NetworkDescriptorList_arraysize==0) ? NULL : new NetworkDescriptor[other.NetworkDescriptorList_arraysize];
    NetworkDescriptorList_arraysize = other.NetworkDescriptorList_arraysize;
    for (unsigned int i=0; i<NetworkDescriptorList_arraysize; i++)
        this->NetworkDescriptorList_var[i] = other.NetworkDescriptorList_var[i];
    this->status_var = other.status_var;
    return *this;
}

void NlmeNetworkDiscovery_confirm::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
    doPacking(b,this->networkCount_var);
    b->pack(NetworkDescriptorList_arraysize);
    doPacking(b,this->NetworkDescriptorList_var,NetworkDescriptorList_arraysize);
    doPacking(b,this->status_var);
}

void NlmeNetworkDiscovery_confirm::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->networkCount_var);
    delete [] this->NetworkDescriptorList_var;
    b->unpack(NetworkDescriptorList_arraysize);
    if (NetworkDescriptorList_arraysize==0) {
        this->NetworkDescriptorList_var = 0;
    } else {
        this->NetworkDescriptorList_var = new NetworkDescriptor[NetworkDescriptorList_arraysize];
        doUnpacking(b,this->NetworkDescriptorList_var,NetworkDescriptorList_arraysize);
    }
    doUnpacking(b,this->status_var);
}

unsigned char NlmeNetworkDiscovery_confirm::getNetworkCount() const
{
    return networkCount_var;
}

void NlmeNetworkDiscovery_confirm::setNetworkCount(unsigned char networkCount_var)
{
    this->networkCount_var = networkCount_var;
}

void NlmeNetworkDiscovery_confirm::setNetworkDescriptorListArraySize(unsigned int size)
{
    NetworkDescriptor *NetworkDescriptorList_var2 = (size==0) ? NULL : new NetworkDescriptor[size];
    unsigned int sz = NetworkDescriptorList_arraysize < size ? NetworkDescriptorList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        NetworkDescriptorList_var2[i] = this->NetworkDescriptorList_var[i];
    NetworkDescriptorList_arraysize = size;
    delete [] this->NetworkDescriptorList_var;
    this->NetworkDescriptorList_var = NetworkDescriptorList_var2;
}

unsigned int NlmeNetworkDiscovery_confirm::getNetworkDescriptorListArraySize() const
{
    return NetworkDescriptorList_arraysize;
}

NetworkDescriptor& NlmeNetworkDiscovery_confirm::getNetworkDescriptorList(unsigned int k)
{
    if (k>=NetworkDescriptorList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", NetworkDescriptorList_arraysize, k);
    return NetworkDescriptorList_var[k];
}

void NlmeNetworkDiscovery_confirm::setNetworkDescriptorList(unsigned int k, const NetworkDescriptor& NetworkDescriptorList_var)
{
    if (k>=NetworkDescriptorList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", NetworkDescriptorList_arraysize, k);
    this->NetworkDescriptorList_var[k]=NetworkDescriptorList_var;
}

unsigned char NlmeNetworkDiscovery_confirm::getStatus() const
{
    return status_var;
}

void NlmeNetworkDiscovery_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

class NlmeNetworkDiscovery_confirmDescriptor : public cClassDescriptor
{
  public:
    NlmeNetworkDiscovery_confirmDescriptor();
    virtual ~NlmeNetworkDiscovery_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmeNetworkDiscovery_confirmDescriptor);

NlmeNetworkDiscovery_confirmDescriptor::NlmeNetworkDiscovery_confirmDescriptor() : cClassDescriptor("NlmeNetworkDiscovery_confirm", "NlmeMsg")
{
}

NlmeNetworkDiscovery_confirmDescriptor::~NlmeNetworkDiscovery_confirmDescriptor()
{
}

bool NlmeNetworkDiscovery_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmeNetworkDiscovery_confirm *>(obj)!=NULL;
}

const char *NlmeNetworkDiscovery_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmeNetworkDiscovery_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int NlmeNetworkDiscovery_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISARRAY | FD_ISCOMPOUND;
        case 2: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *NlmeNetworkDiscovery_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "networkCount";
        case 1: return "NetworkDescriptorList";
        case 2: return "status";
        default: return NULL;
    }
}

const char *NlmeNetworkDiscovery_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "NetworkDescriptor";
        case 2: return "unsigned char";
        default: return NULL;
    }
}

const char *NlmeNetworkDiscovery_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"enum")) return "MacEnum";
            return NULL;
        default: return NULL;
    }
}

int NlmeNetworkDiscovery_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkDiscovery_confirm *pp = (NlmeNetworkDiscovery_confirm *)object; (void)pp;
    switch (field) {
        case 1: return pp->getNetworkDescriptorListArraySize();
        default: return 0;
    }
}

bool NlmeNetworkDiscovery_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkDiscovery_confirm *pp = (NlmeNetworkDiscovery_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getNetworkCount(),resultbuf,bufsize); return true;
        case 1: {std::stringstream out; out << pp->getNetworkDescriptorList(i); opp_strprettytrunc(resultbuf,out.str().c_str(),bufsize-1); return true;}
        case 2: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool NlmeNetworkDiscovery_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkDiscovery_confirm *pp = (NlmeNetworkDiscovery_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setNetworkCount(string2ulong(value)); return true;
        case 2: pp->setStatus(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NlmeNetworkDiscovery_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1: return "NetworkDescriptor"; break;
        default: return NULL;
    }
}

void *NlmeNetworkDiscovery_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmeNetworkDiscovery_confirm *pp = (NlmeNetworkDiscovery_confirm *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getNetworkDescriptorList(i)); break;
        default: return NULL;
    }
}

Register_Class(NlmePermitJoining_request);

NlmePermitJoining_request::NlmePermitJoining_request(const char *name, int kind) : NlmeMsg(name,kind)
{
    this->permitDuration_var = 0;
}

NlmePermitJoining_request::NlmePermitJoining_request(const NlmePermitJoining_request& other) : NlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

NlmePermitJoining_request::~NlmePermitJoining_request()
{
}

NlmePermitJoining_request& NlmePermitJoining_request::operator=(const NlmePermitJoining_request& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    this->permitDuration_var = other.permitDuration_var;
    return *this;
}

void NlmePermitJoining_request::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
    doPacking(b,this->permitDuration_var);
}

void NlmePermitJoining_request::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->permitDuration_var);
}

unsigned char NlmePermitJoining_request::getPermitDuration() const
{
    return permitDuration_var;
}

void NlmePermitJoining_request::setPermitDuration(unsigned char permitDuration_var)
{
    this->permitDuration_var = permitDuration_var;
}

class NlmePermitJoining_requestDescriptor : public cClassDescriptor
{
  public:
    NlmePermitJoining_requestDescriptor();
    virtual ~NlmePermitJoining_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmePermitJoining_requestDescriptor);

NlmePermitJoining_requestDescriptor::NlmePermitJoining_requestDescriptor() : cClassDescriptor("NlmePermitJoining_request", "NlmeMsg")
{
}

NlmePermitJoining_requestDescriptor::~NlmePermitJoining_requestDescriptor()
{
}

bool NlmePermitJoining_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmePermitJoining_request *>(obj)!=NULL;
}

const char *NlmePermitJoining_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmePermitJoining_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int NlmePermitJoining_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *NlmePermitJoining_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "permitDuration";
        default: return NULL;
    }
}

const char *NlmePermitJoining_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        default: return NULL;
    }
}

const char *NlmePermitJoining_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NlmePermitJoining_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmePermitJoining_request *pp = (NlmePermitJoining_request *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmePermitJoining_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmePermitJoining_request *pp = (NlmePermitJoining_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getPermitDuration(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool NlmePermitJoining_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmePermitJoining_request *pp = (NlmePermitJoining_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setPermitDuration(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NlmePermitJoining_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmePermitJoining_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmePermitJoining_request *pp = (NlmePermitJoining_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NlmePermitJoining_confirm);

NlmePermitJoining_confirm::NlmePermitJoining_confirm(const char *name, int kind) : NlmeMsg(name,kind)
{
    this->status_var = 0;
}

NlmePermitJoining_confirm::NlmePermitJoining_confirm(const NlmePermitJoining_confirm& other) : NlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

NlmePermitJoining_confirm::~NlmePermitJoining_confirm()
{
}

NlmePermitJoining_confirm& NlmePermitJoining_confirm::operator=(const NlmePermitJoining_confirm& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    this->status_var = other.status_var;
    return *this;
}

void NlmePermitJoining_confirm::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
}

void NlmePermitJoining_confirm::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
}

unsigned char NlmePermitJoining_confirm::getStatus() const
{
    return status_var;
}

void NlmePermitJoining_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

class NlmePermitJoining_confirmDescriptor : public cClassDescriptor
{
  public:
    NlmePermitJoining_confirmDescriptor();
    virtual ~NlmePermitJoining_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmePermitJoining_confirmDescriptor);

NlmePermitJoining_confirmDescriptor::NlmePermitJoining_confirmDescriptor() : cClassDescriptor("NlmePermitJoining_confirm", "NlmeMsg")
{
}

NlmePermitJoining_confirmDescriptor::~NlmePermitJoining_confirmDescriptor()
{
}

bool NlmePermitJoining_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmePermitJoining_confirm *>(obj)!=NULL;
}

const char *NlmePermitJoining_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmePermitJoining_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int NlmePermitJoining_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *NlmePermitJoining_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        default: return NULL;
    }
}

const char *NlmePermitJoining_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        default: return NULL;
    }
}

const char *NlmePermitJoining_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "MacEnum";
            return NULL;
        default: return NULL;
    }
}

int NlmePermitJoining_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmePermitJoining_confirm *pp = (NlmePermitJoining_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmePermitJoining_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmePermitJoining_confirm *pp = (NlmePermitJoining_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool NlmePermitJoining_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmePermitJoining_confirm *pp = (NlmePermitJoining_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NlmePermitJoining_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmePermitJoining_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmePermitJoining_confirm *pp = (NlmePermitJoining_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NlmeStartRouter_request);

NlmeStartRouter_request::NlmeStartRouter_request(const char *name, int kind) : NlmeMsg(name,kind)
{
    this->beaconOrder_var = 0;
    this->superframeOrder_var = 0;
    this->batteryLifeExtension_var = 0;
}

NlmeStartRouter_request::NlmeStartRouter_request(const NlmeStartRouter_request& other) : NlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

NlmeStartRouter_request::~NlmeStartRouter_request()
{
}

NlmeStartRouter_request& NlmeStartRouter_request::operator=(const NlmeStartRouter_request& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    this->beaconOrder_var = other.beaconOrder_var;
    this->superframeOrder_var = other.superframeOrder_var;
    this->batteryLifeExtension_var = other.batteryLifeExtension_var;
    return *this;
}

void NlmeStartRouter_request::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
    doPacking(b,this->beaconOrder_var);
    doPacking(b,this->superframeOrder_var);
    doPacking(b,this->batteryLifeExtension_var);
}

void NlmeStartRouter_request::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->beaconOrder_var);
    doUnpacking(b,this->superframeOrder_var);
    doUnpacking(b,this->batteryLifeExtension_var);
}

unsigned char NlmeStartRouter_request::getBeaconOrder() const
{
    return beaconOrder_var;
}

void NlmeStartRouter_request::setBeaconOrder(unsigned char beaconOrder_var)
{
    this->beaconOrder_var = beaconOrder_var;
}

unsigned char NlmeStartRouter_request::getSuperframeOrder() const
{
    return superframeOrder_var;
}

void NlmeStartRouter_request::setSuperframeOrder(unsigned char superframeOrder_var)
{
    this->superframeOrder_var = superframeOrder_var;
}

bool NlmeStartRouter_request::getBatteryLifeExtension() const
{
    return batteryLifeExtension_var;
}

void NlmeStartRouter_request::setBatteryLifeExtension(bool batteryLifeExtension_var)
{
    this->batteryLifeExtension_var = batteryLifeExtension_var;
}

class NlmeStartRouter_requestDescriptor : public cClassDescriptor
{
  public:
    NlmeStartRouter_requestDescriptor();
    virtual ~NlmeStartRouter_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmeStartRouter_requestDescriptor);

NlmeStartRouter_requestDescriptor::NlmeStartRouter_requestDescriptor() : cClassDescriptor("NlmeStartRouter_request", "NlmeMsg")
{
}

NlmeStartRouter_requestDescriptor::~NlmeStartRouter_requestDescriptor()
{
}

bool NlmeStartRouter_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmeStartRouter_request *>(obj)!=NULL;
}

const char *NlmeStartRouter_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmeStartRouter_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int NlmeStartRouter_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *NlmeStartRouter_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "beaconOrder";
        case 1: return "superframeOrder";
        case 2: return "batteryLifeExtension";
        default: return NULL;
    }
}

const char *NlmeStartRouter_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned char";
        case 2: return "bool";
        default: return NULL;
    }
}

const char *NlmeStartRouter_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NlmeStartRouter_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmeStartRouter_request *pp = (NlmeStartRouter_request *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmeStartRouter_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmeStartRouter_request *pp = (NlmeStartRouter_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getBeaconOrder(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getSuperframeOrder(),resultbuf,bufsize); return true;
        case 2: bool2string(pp->getBatteryLifeExtension(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool NlmeStartRouter_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmeStartRouter_request *pp = (NlmeStartRouter_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setBeaconOrder(string2ulong(value)); return true;
        case 1: pp->setSuperframeOrder(string2ulong(value)); return true;
        case 2: pp->setBatteryLifeExtension(string2bool(value)); return true;
        default: return false;
    }
}

const char *NlmeStartRouter_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmeStartRouter_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmeStartRouter_request *pp = (NlmeStartRouter_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NlmeStartRouter_confirm);

NlmeStartRouter_confirm::NlmeStartRouter_confirm(const char *name, int kind) : NlmeMsg(name,kind)
{
    this->status_var = 0;
}

NlmeStartRouter_confirm::NlmeStartRouter_confirm(const NlmeStartRouter_confirm& other) : NlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

NlmeStartRouter_confirm::~NlmeStartRouter_confirm()
{
}

NlmeStartRouter_confirm& NlmeStartRouter_confirm::operator=(const NlmeStartRouter_confirm& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    this->status_var = other.status_var;
    return *this;
}

void NlmeStartRouter_confirm::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
}

void NlmeStartRouter_confirm::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
}

unsigned char NlmeStartRouter_confirm::getStatus() const
{
    return status_var;
}

void NlmeStartRouter_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

class NlmeStartRouter_confirmDescriptor : public cClassDescriptor
{
  public:
    NlmeStartRouter_confirmDescriptor();
    virtual ~NlmeStartRouter_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmeStartRouter_confirmDescriptor);

NlmeStartRouter_confirmDescriptor::NlmeStartRouter_confirmDescriptor() : cClassDescriptor("NlmeStartRouter_confirm", "NlmeMsg")
{
}

NlmeStartRouter_confirmDescriptor::~NlmeStartRouter_confirmDescriptor()
{
}

bool NlmeStartRouter_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmeStartRouter_confirm *>(obj)!=NULL;
}

const char *NlmeStartRouter_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmeStartRouter_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int NlmeStartRouter_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *NlmeStartRouter_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        default: return NULL;
    }
}

const char *NlmeStartRouter_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        default: return NULL;
    }
}

const char *NlmeStartRouter_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "MacEnum";
            return NULL;
        default: return NULL;
    }
}

int NlmeStartRouter_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmeStartRouter_confirm *pp = (NlmeStartRouter_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmeStartRouter_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmeStartRouter_confirm *pp = (NlmeStartRouter_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool NlmeStartRouter_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmeStartRouter_confirm *pp = (NlmeStartRouter_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NlmeStartRouter_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmeStartRouter_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmeStartRouter_confirm *pp = (NlmeStartRouter_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NlmeJoin_request);

NlmeJoin_request::NlmeJoin_request(const char *name, int kind) : NlmeMsg(name,kind)
{
    this->panId_var = 0;
    this->joinAsRouter_var = 0;
    this->rejoinNetwork_var = 0;
    this->scanChannels_var = 0;
    this->scanDuration_var = 0;
    this->powerSource_var = 0;
    this->rxOnWhenIdle_var = 0;
    this->macSecurity_var = 0;
}

NlmeJoin_request::NlmeJoin_request(const NlmeJoin_request& other) : NlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

NlmeJoin_request::~NlmeJoin_request()
{
}

NlmeJoin_request& NlmeJoin_request::operator=(const NlmeJoin_request& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    this->panId_var = other.panId_var;
    this->joinAsRouter_var = other.joinAsRouter_var;
    this->rejoinNetwork_var = other.rejoinNetwork_var;
    this->scanChannels_var = other.scanChannels_var;
    this->scanDuration_var = other.scanDuration_var;
    this->powerSource_var = other.powerSource_var;
    this->rxOnWhenIdle_var = other.rxOnWhenIdle_var;
    this->macSecurity_var = other.macSecurity_var;
    return *this;
}

void NlmeJoin_request::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
    doPacking(b,this->panId_var);
    doPacking(b,this->joinAsRouter_var);
    doPacking(b,this->rejoinNetwork_var);
    doPacking(b,this->scanChannels_var);
    doPacking(b,this->scanDuration_var);
    doPacking(b,this->powerSource_var);
    doPacking(b,this->rxOnWhenIdle_var);
    doPacking(b,this->macSecurity_var);
}

void NlmeJoin_request::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->panId_var);
    doUnpacking(b,this->joinAsRouter_var);
    doUnpacking(b,this->rejoinNetwork_var);
    doUnpacking(b,this->scanChannels_var);
    doUnpacking(b,this->scanDuration_var);
    doUnpacking(b,this->powerSource_var);
    doUnpacking(b,this->rxOnWhenIdle_var);
    doUnpacking(b,this->macSecurity_var);
}

unsigned short NlmeJoin_request::getPanId() const
{
    return panId_var;
}

void NlmeJoin_request::setPanId(unsigned short panId_var)
{
    this->panId_var = panId_var;
}

bool NlmeJoin_request::getJoinAsRouter() const
{
    return joinAsRouter_var;
}

void NlmeJoin_request::setJoinAsRouter(bool joinAsRouter_var)
{
    this->joinAsRouter_var = joinAsRouter_var;
}

bool NlmeJoin_request::getRejoinNetwork() const
{
    return rejoinNetwork_var;
}

void NlmeJoin_request::setRejoinNetwork(bool rejoinNetwork_var)
{
    this->rejoinNetwork_var = rejoinNetwork_var;
}

unsigned int NlmeJoin_request::getScanChannels() const
{
    return scanChannels_var;
}

void NlmeJoin_request::setScanChannels(unsigned int scanChannels_var)
{
    this->scanChannels_var = scanChannels_var;
}

unsigned char NlmeJoin_request::getScanDuration() const
{
    return scanDuration_var;
}

void NlmeJoin_request::setScanDuration(unsigned char scanDuration_var)
{
    this->scanDuration_var = scanDuration_var;
}

bool NlmeJoin_request::getPowerSource() const
{
    return powerSource_var;
}

void NlmeJoin_request::setPowerSource(bool powerSource_var)
{
    this->powerSource_var = powerSource_var;
}

bool NlmeJoin_request::getRxOnWhenIdle() const
{
    return rxOnWhenIdle_var;
}

void NlmeJoin_request::setRxOnWhenIdle(bool rxOnWhenIdle_var)
{
    this->rxOnWhenIdle_var = rxOnWhenIdle_var;
}

bool NlmeJoin_request::getMacSecurity() const
{
    return macSecurity_var;
}

void NlmeJoin_request::setMacSecurity(bool macSecurity_var)
{
    this->macSecurity_var = macSecurity_var;
}

class NlmeJoin_requestDescriptor : public cClassDescriptor
{
  public:
    NlmeJoin_requestDescriptor();
    virtual ~NlmeJoin_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmeJoin_requestDescriptor);

NlmeJoin_requestDescriptor::NlmeJoin_requestDescriptor() : cClassDescriptor("NlmeJoin_request", "NlmeMsg")
{
}

NlmeJoin_requestDescriptor::~NlmeJoin_requestDescriptor()
{
}

bool NlmeJoin_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmeJoin_request *>(obj)!=NULL;
}

const char *NlmeJoin_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmeJoin_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int NlmeJoin_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISEDITABLE;
        case 5: return FD_ISEDITABLE;
        case 6: return FD_ISEDITABLE;
        case 7: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *NlmeJoin_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "panId";
        case 1: return "joinAsRouter";
        case 2: return "rejoinNetwork";
        case 3: return "scanChannels";
        case 4: return "scanDuration";
        case 5: return "powerSource";
        case 6: return "rxOnWhenIdle";
        case 7: return "macSecurity";
        default: return NULL;
    }
}

const char *NlmeJoin_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned short";
        case 1: return "bool";
        case 2: return "bool";
        case 3: return "unsigned int";
        case 4: return "unsigned char";
        case 5: return "bool";
        case 6: return "bool";
        case 7: return "bool";
        default: return NULL;
    }
}

const char *NlmeJoin_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NlmeJoin_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_request *pp = (NlmeJoin_request *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmeJoin_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_request *pp = (NlmeJoin_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getPanId(),resultbuf,bufsize); return true;
        case 1: bool2string(pp->getJoinAsRouter(),resultbuf,bufsize); return true;
        case 2: bool2string(pp->getRejoinNetwork(),resultbuf,bufsize); return true;
        case 3: ulong2string(pp->getScanChannels(),resultbuf,bufsize); return true;
        case 4: ulong2string(pp->getScanDuration(),resultbuf,bufsize); return true;
        case 5: bool2string(pp->getPowerSource(),resultbuf,bufsize); return true;
        case 6: bool2string(pp->getRxOnWhenIdle(),resultbuf,bufsize); return true;
        case 7: bool2string(pp->getMacSecurity(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool NlmeJoin_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_request *pp = (NlmeJoin_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setPanId(string2ulong(value)); return true;
        case 1: pp->setJoinAsRouter(string2bool(value)); return true;
        case 2: pp->setRejoinNetwork(string2bool(value)); return true;
        case 3: pp->setScanChannels(string2ulong(value)); return true;
        case 4: pp->setScanDuration(string2ulong(value)); return true;
        case 5: pp->setPowerSource(string2bool(value)); return true;
        case 6: pp->setRxOnWhenIdle(string2bool(value)); return true;
        case 7: pp->setMacSecurity(string2bool(value)); return true;
        default: return false;
    }
}

const char *NlmeJoin_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmeJoin_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_request *pp = (NlmeJoin_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NlmeJoin_indication);

NlmeJoin_indication::NlmeJoin_indication(const char *name, int kind) : NlmeMsg(name,kind)
{
}

NlmeJoin_indication::NlmeJoin_indication(const NlmeJoin_indication& other) : NlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

NlmeJoin_indication::~NlmeJoin_indication()
{
}

NlmeJoin_indication& NlmeJoin_indication::operator=(const NlmeJoin_indication& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    return *this;
}

void NlmeJoin_indication::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
}

void NlmeJoin_indication::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
}

class NlmeJoin_indicationDescriptor : public cClassDescriptor
{
  public:
    NlmeJoin_indicationDescriptor();
    virtual ~NlmeJoin_indicationDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmeJoin_indicationDescriptor);

NlmeJoin_indicationDescriptor::NlmeJoin_indicationDescriptor() : cClassDescriptor("NlmeJoin_indication", "NlmeMsg")
{
}

NlmeJoin_indicationDescriptor::~NlmeJoin_indicationDescriptor()
{
}

bool NlmeJoin_indicationDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmeJoin_indication *>(obj)!=NULL;
}

const char *NlmeJoin_indicationDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmeJoin_indicationDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int NlmeJoin_indicationDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return 0;
    }
}

const char *NlmeJoin_indicationDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *NlmeJoin_indicationDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *NlmeJoin_indicationDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NlmeJoin_indicationDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_indication *pp = (NlmeJoin_indication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmeJoin_indicationDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_indication *pp = (NlmeJoin_indication *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

bool NlmeJoin_indicationDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_indication *pp = (NlmeJoin_indication *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NlmeJoin_indicationDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmeJoin_indicationDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_indication *pp = (NlmeJoin_indication *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NlmeJoin_confirm);

NlmeJoin_confirm::NlmeJoin_confirm(const char *name, int kind) : NlmeMsg(name,kind)
{
    this->status_var = 0;
    this->networkAddress_var = 0;
    this->extendedPanId_var = 0;
    this->currentChannel_var = 0;
}

NlmeJoin_confirm::NlmeJoin_confirm(const NlmeJoin_confirm& other) : NlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

NlmeJoin_confirm::~NlmeJoin_confirm()
{
}

NlmeJoin_confirm& NlmeJoin_confirm::operator=(const NlmeJoin_confirm& other)
{
    if (this==&other) return *this;
    NlmeMsg::operator=(other);
    this->status_var = other.status_var;
    this->networkAddress_var = other.networkAddress_var;
    this->extendedPanId_var = other.extendedPanId_var;
    this->currentChannel_var = other.currentChannel_var;
    return *this;
}

void NlmeJoin_confirm::parsimPack(cCommBuffer *b)
{
    NlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
    doPacking(b,this->networkAddress_var);
    doPacking(b,this->extendedPanId_var);
    doPacking(b,this->currentChannel_var);
}

void NlmeJoin_confirm::parsimUnpack(cCommBuffer *b)
{
    NlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->networkAddress_var);
    doUnpacking(b,this->extendedPanId_var);
    doUnpacking(b,this->currentChannel_var);
}

unsigned char NlmeJoin_confirm::getStatus() const
{
    return status_var;
}

void NlmeJoin_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

unsigned short NlmeJoin_confirm::getNetworkAddress() const
{
    return networkAddress_var;
}

void NlmeJoin_confirm::setNetworkAddress(unsigned short networkAddress_var)
{
    this->networkAddress_var = networkAddress_var;
}

unsigned long NlmeJoin_confirm::getExtendedPanId() const
{
    return extendedPanId_var;
}

void NlmeJoin_confirm::setExtendedPanId(unsigned long extendedPanId_var)
{
    this->extendedPanId_var = extendedPanId_var;
}

unsigned char NlmeJoin_confirm::getCurrentChannel() const
{
    return currentChannel_var;
}

void NlmeJoin_confirm::setCurrentChannel(unsigned char currentChannel_var)
{
    this->currentChannel_var = currentChannel_var;
}

class NlmeJoin_confirmDescriptor : public cClassDescriptor
{
  public:
    NlmeJoin_confirmDescriptor();
    virtual ~NlmeJoin_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NlmeJoin_confirmDescriptor);

NlmeJoin_confirmDescriptor::NlmeJoin_confirmDescriptor() : cClassDescriptor("NlmeJoin_confirm", "NlmeMsg")
{
}

NlmeJoin_confirmDescriptor::~NlmeJoin_confirmDescriptor()
{
}

bool NlmeJoin_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NlmeJoin_confirm *>(obj)!=NULL;
}

const char *NlmeJoin_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NlmeJoin_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int NlmeJoin_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *NlmeJoin_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        case 1: return "networkAddress";
        case 2: return "extendedPanId";
        case 3: return "currentChannel";
        default: return NULL;
    }
}

const char *NlmeJoin_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned short";
        case 2: return "unsigned long";
        case 3: return "unsigned char";
        default: return NULL;
    }
}

const char *NlmeJoin_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NlmeJoin_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_confirm *pp = (NlmeJoin_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NlmeJoin_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_confirm *pp = (NlmeJoin_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getNetworkAddress(),resultbuf,bufsize); return true;
        case 2: ulong2string(pp->getExtendedPanId(),resultbuf,bufsize); return true;
        case 3: ulong2string(pp->getCurrentChannel(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool NlmeJoin_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_confirm *pp = (NlmeJoin_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        case 1: pp->setNetworkAddress(string2ulong(value)); return true;
        case 2: pp->setExtendedPanId(string2ulong(value)); return true;
        case 3: pp->setCurrentChannel(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NlmeJoin_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NlmeJoin_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NlmeJoin_confirm *pp = (NlmeJoin_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(NldeMsg);

NldeMsg::NldeMsg(const char *name, int kind) : cPacket(name,kind)
{
}

NldeMsg::NldeMsg(const NldeMsg& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

NldeMsg::~NldeMsg()
{
}

NldeMsg& NldeMsg::operator=(const NldeMsg& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void NldeMsg::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void NldeMsg::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class NldeMsgDescriptor : public cClassDescriptor
{
  public:
    NldeMsgDescriptor();
    virtual ~NldeMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NldeMsgDescriptor);

NldeMsgDescriptor::NldeMsgDescriptor() : cClassDescriptor("NldeMsg", "cPacket")
{
}

NldeMsgDescriptor::~NldeMsgDescriptor()
{
}

bool NldeMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NldeMsg *>(obj)!=NULL;
}

const char *NldeMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NldeMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int NldeMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return 0;
    }
}

const char *NldeMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *NldeMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *NldeMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NldeMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NldeMsg *pp = (NldeMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool NldeMsgDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    NldeMsg *pp = (NldeMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

bool NldeMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NldeMsg *pp = (NldeMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *NldeMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *NldeMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NldeMsg *pp = (NldeMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeMsg);

MlmeMsg::MlmeMsg(const char *name, int kind) : cPacket(name,kind)
{
}

MlmeMsg::MlmeMsg(const MlmeMsg& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

MlmeMsg::~MlmeMsg()
{
}

MlmeMsg& MlmeMsg::operator=(const MlmeMsg& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void MlmeMsg::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void MlmeMsg::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class MlmeMsgDescriptor : public cClassDescriptor
{
  public:
    MlmeMsgDescriptor();
    virtual ~MlmeMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeMsgDescriptor);

MlmeMsgDescriptor::MlmeMsgDescriptor() : cClassDescriptor("MlmeMsg", "cPacket")
{
}

MlmeMsgDescriptor::~MlmeMsgDescriptor()
{
}

bool MlmeMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeMsg *>(obj)!=NULL;
}

const char *MlmeMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int MlmeMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return 0;
    }
}

const char *MlmeMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *MlmeMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *MlmeMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MlmeMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeMsg *pp = (MlmeMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool MlmeMsgDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeMsg *pp = (MlmeMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

bool MlmeMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeMsg *pp = (MlmeMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MlmeMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MlmeMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeMsg *pp = (MlmeMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeScan_request);

MlmeScan_request::MlmeScan_request(const char *name, int kind) : MlmeMsg(name,kind)
{
    this->scanType_var = 0;
    this->scanChannels_var = 0;
    this->scanDuration_var = 0;
    this->channelPage_var = 0;
    this->securityLevel_var = 0;
    this->keyIdMode_var = 0;
    keySource_arraysize = 0;
    this->keySource_var = 0;
    this->kedyIndex_var = 0;
}

MlmeScan_request::MlmeScan_request(const MlmeScan_request& other) : MlmeMsg()
{
    setName(other.getName());
    keySource_arraysize = 0;
    this->keySource_var = 0;
    operator=(other);
}

MlmeScan_request::~MlmeScan_request()
{
    delete [] keySource_var;
}

MlmeScan_request& MlmeScan_request::operator=(const MlmeScan_request& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    this->scanType_var = other.scanType_var;
    this->scanChannels_var = other.scanChannels_var;
    this->scanDuration_var = other.scanDuration_var;
    this->channelPage_var = other.channelPage_var;
    this->securityLevel_var = other.securityLevel_var;
    this->keyIdMode_var = other.keyIdMode_var;
    delete [] this->keySource_var;
    this->keySource_var = (other.keySource_arraysize==0) ? NULL : new unsigned char[other.keySource_arraysize];
    keySource_arraysize = other.keySource_arraysize;
    for (unsigned int i=0; i<keySource_arraysize; i++)
        this->keySource_var[i] = other.keySource_var[i];
    this->kedyIndex_var = other.kedyIndex_var;
    return *this;
}

void MlmeScan_request::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
    doPacking(b,this->scanType_var);
    doPacking(b,this->scanChannels_var);
    doPacking(b,this->scanDuration_var);
    doPacking(b,this->channelPage_var);
    doPacking(b,this->securityLevel_var);
    doPacking(b,this->keyIdMode_var);
    b->pack(keySource_arraysize);
    doPacking(b,this->keySource_var,keySource_arraysize);
    doPacking(b,this->kedyIndex_var);
}

void MlmeScan_request::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->scanType_var);
    doUnpacking(b,this->scanChannels_var);
    doUnpacking(b,this->scanDuration_var);
    doUnpacking(b,this->channelPage_var);
    doUnpacking(b,this->securityLevel_var);
    doUnpacking(b,this->keyIdMode_var);
    delete [] this->keySource_var;
    b->unpack(keySource_arraysize);
    if (keySource_arraysize==0) {
        this->keySource_var = 0;
    } else {
        this->keySource_var = new unsigned char[keySource_arraysize];
        doUnpacking(b,this->keySource_var,keySource_arraysize);
    }
    doUnpacking(b,this->kedyIndex_var);
}

unsigned char MlmeScan_request::getScanType() const
{
    return scanType_var;
}

void MlmeScan_request::setScanType(unsigned char scanType_var)
{
    this->scanType_var = scanType_var;
}

unsigned int MlmeScan_request::getScanChannels() const
{
    return scanChannels_var;
}

void MlmeScan_request::setScanChannels(unsigned int scanChannels_var)
{
    this->scanChannels_var = scanChannels_var;
}

unsigned char MlmeScan_request::getScanDuration() const
{
    return scanDuration_var;
}

void MlmeScan_request::setScanDuration(unsigned char scanDuration_var)
{
    this->scanDuration_var = scanDuration_var;
}

unsigned char MlmeScan_request::getChannelPage() const
{
    return channelPage_var;
}

void MlmeScan_request::setChannelPage(unsigned char channelPage_var)
{
    this->channelPage_var = channelPage_var;
}

unsigned char MlmeScan_request::getSecurityLevel() const
{
    return securityLevel_var;
}

void MlmeScan_request::setSecurityLevel(unsigned char securityLevel_var)
{
    this->securityLevel_var = securityLevel_var;
}

unsigned char MlmeScan_request::getKeyIdMode() const
{
    return keyIdMode_var;
}

void MlmeScan_request::setKeyIdMode(unsigned char keyIdMode_var)
{
    this->keyIdMode_var = keyIdMode_var;
}

void MlmeScan_request::setKeySourceArraySize(unsigned int size)
{
    unsigned char *keySource_var2 = (size==0) ? NULL : new unsigned char[size];
    unsigned int sz = keySource_arraysize < size ? keySource_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        keySource_var2[i] = this->keySource_var[i];
    for (unsigned int i=sz; i<size; i++)
        keySource_var2[i] = 0;
    keySource_arraysize = size;
    delete [] this->keySource_var;
    this->keySource_var = keySource_var2;
}

unsigned int MlmeScan_request::getKeySourceArraySize() const
{
    return keySource_arraysize;
}

unsigned char MlmeScan_request::getKeySource(unsigned int k) const
{
    if (k>=keySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", keySource_arraysize, k);
    return keySource_var[k];
}

void MlmeScan_request::setKeySource(unsigned int k, unsigned char keySource_var)
{
    if (k>=keySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", keySource_arraysize, k);
    this->keySource_var[k]=keySource_var;
}

unsigned char MlmeScan_request::getKedyIndex() const
{
    return kedyIndex_var;
}

void MlmeScan_request::setKedyIndex(unsigned char kedyIndex_var)
{
    this->kedyIndex_var = kedyIndex_var;
}

class MlmeScan_requestDescriptor : public cClassDescriptor
{
  public:
    MlmeScan_requestDescriptor();
    virtual ~MlmeScan_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeScan_requestDescriptor);

MlmeScan_requestDescriptor::MlmeScan_requestDescriptor() : cClassDescriptor("MlmeScan_request", "MlmeMsg")
{
}

MlmeScan_requestDescriptor::~MlmeScan_requestDescriptor()
{
}

bool MlmeScan_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeScan_request *>(obj)!=NULL;
}

const char *MlmeScan_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeScan_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int MlmeScan_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISEDITABLE;
        case 5: return FD_ISEDITABLE;
        case 6: return FD_ISARRAY | FD_ISEDITABLE;
        case 7: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MlmeScan_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "scanType";
        case 1: return "scanChannels";
        case 2: return "scanDuration";
        case 3: return "channelPage";
        case 4: return "securityLevel";
        case 5: return "keyIdMode";
        case 6: return "keySource";
        case 7: return "kedyIndex";
        default: return NULL;
    }
}

const char *MlmeScan_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned int";
        case 2: return "unsigned char";
        case 3: return "unsigned char";
        case 4: return "unsigned char";
        case 5: return "unsigned char";
        case 6: return "unsigned char";
        case 7: return "unsigned char";
        default: return NULL;
    }
}

const char *MlmeScan_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MlmeScan_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeScan_request *pp = (MlmeScan_request *)object; (void)pp;
    switch (field) {
        case 6: return pp->getKeySourceArraySize();
        default: return 0;
    }
}

bool MlmeScan_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeScan_request *pp = (MlmeScan_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getScanType(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getScanChannels(),resultbuf,bufsize); return true;
        case 2: ulong2string(pp->getScanDuration(),resultbuf,bufsize); return true;
        case 3: ulong2string(pp->getChannelPage(),resultbuf,bufsize); return true;
        case 4: ulong2string(pp->getSecurityLevel(),resultbuf,bufsize); return true;
        case 5: ulong2string(pp->getKeyIdMode(),resultbuf,bufsize); return true;
        case 6: ulong2string(pp->getKeySource(i),resultbuf,bufsize); return true;
        case 7: ulong2string(pp->getKedyIndex(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MlmeScan_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeScan_request *pp = (MlmeScan_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setScanType(string2ulong(value)); return true;
        case 1: pp->setScanChannels(string2ulong(value)); return true;
        case 2: pp->setScanDuration(string2ulong(value)); return true;
        case 3: pp->setChannelPage(string2ulong(value)); return true;
        case 4: pp->setSecurityLevel(string2ulong(value)); return true;
        case 5: pp->setKeyIdMode(string2ulong(value)); return true;
        case 6: pp->setKeySource(i,string2ulong(value)); return true;
        case 7: pp->setKedyIndex(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MlmeScan_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MlmeScan_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeScan_request *pp = (MlmeScan_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeScan_confirm);

MlmeScan_confirm::MlmeScan_confirm(const char *name, int kind) : MlmeMsg(name,kind)
{
    this->status_var = 0;
    this->scanType_var = 0;
    this->channelPage_var = 0;
    this->unscannedChannels_var = 0;
    this->resultListSize_var = 0;
    energyDetectList_arraysize = 0;
    this->energyDetectList_var = 0;
    panDescriptorList_arraysize = 0;
    this->panDescriptorList_var = 0;
}

MlmeScan_confirm::MlmeScan_confirm(const MlmeScan_confirm& other) : MlmeMsg()
{
    setName(other.getName());
    energyDetectList_arraysize = 0;
    this->energyDetectList_var = 0;
    panDescriptorList_arraysize = 0;
    this->panDescriptorList_var = 0;
    operator=(other);
}

MlmeScan_confirm::~MlmeScan_confirm()
{
    delete [] energyDetectList_var;
    delete [] panDescriptorList_var;
}

MlmeScan_confirm& MlmeScan_confirm::operator=(const MlmeScan_confirm& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    this->status_var = other.status_var;
    this->scanType_var = other.scanType_var;
    this->channelPage_var = other.channelPage_var;
    this->unscannedChannels_var = other.unscannedChannels_var;
    this->resultListSize_var = other.resultListSize_var;
    delete [] this->energyDetectList_var;
    this->energyDetectList_var = (other.energyDetectList_arraysize==0) ? NULL : new unsigned char[other.energyDetectList_arraysize];
    energyDetectList_arraysize = other.energyDetectList_arraysize;
    for (unsigned int i=0; i<energyDetectList_arraysize; i++)
        this->energyDetectList_var[i] = other.energyDetectList_var[i];
    delete [] this->panDescriptorList_var;
    this->panDescriptorList_var = (other.panDescriptorList_arraysize==0) ? NULL : new PanDescriptor[other.panDescriptorList_arraysize];
    panDescriptorList_arraysize = other.panDescriptorList_arraysize;
    for (unsigned int i=0; i<panDescriptorList_arraysize; i++)
        this->panDescriptorList_var[i] = other.panDescriptorList_var[i];
    return *this;
}

void MlmeScan_confirm::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
    doPacking(b,this->scanType_var);
    doPacking(b,this->channelPage_var);
    doPacking(b,this->unscannedChannels_var);
    doPacking(b,this->resultListSize_var);
    b->pack(energyDetectList_arraysize);
    doPacking(b,this->energyDetectList_var,energyDetectList_arraysize);
    b->pack(panDescriptorList_arraysize);
    doPacking(b,this->panDescriptorList_var,panDescriptorList_arraysize);
}

void MlmeScan_confirm::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->scanType_var);
    doUnpacking(b,this->channelPage_var);
    doUnpacking(b,this->unscannedChannels_var);
    doUnpacking(b,this->resultListSize_var);
    delete [] this->energyDetectList_var;
    b->unpack(energyDetectList_arraysize);
    if (energyDetectList_arraysize==0) {
        this->energyDetectList_var = 0;
    } else {
        this->energyDetectList_var = new unsigned char[energyDetectList_arraysize];
        doUnpacking(b,this->energyDetectList_var,energyDetectList_arraysize);
    }
    delete [] this->panDescriptorList_var;
    b->unpack(panDescriptorList_arraysize);
    if (panDescriptorList_arraysize==0) {
        this->panDescriptorList_var = 0;
    } else {
        this->panDescriptorList_var = new PanDescriptor[panDescriptorList_arraysize];
        doUnpacking(b,this->panDescriptorList_var,panDescriptorList_arraysize);
    }
}

unsigned char MlmeScan_confirm::getStatus() const
{
    return status_var;
}

void MlmeScan_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

unsigned char MlmeScan_confirm::getScanType() const
{
    return scanType_var;
}

void MlmeScan_confirm::setScanType(unsigned char scanType_var)
{
    this->scanType_var = scanType_var;
}

unsigned char MlmeScan_confirm::getChannelPage() const
{
    return channelPage_var;
}

void MlmeScan_confirm::setChannelPage(unsigned char channelPage_var)
{
    this->channelPage_var = channelPage_var;
}

unsigned int MlmeScan_confirm::getUnscannedChannels() const
{
    return unscannedChannels_var;
}

void MlmeScan_confirm::setUnscannedChannels(unsigned int unscannedChannels_var)
{
    this->unscannedChannels_var = unscannedChannels_var;
}

unsigned int MlmeScan_confirm::getResultListSize() const
{
    return resultListSize_var;
}

void MlmeScan_confirm::setResultListSize(unsigned int resultListSize_var)
{
    this->resultListSize_var = resultListSize_var;
}

void MlmeScan_confirm::setEnergyDetectListArraySize(unsigned int size)
{
    unsigned char *energyDetectList_var2 = (size==0) ? NULL : new unsigned char[size];
    unsigned int sz = energyDetectList_arraysize < size ? energyDetectList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        energyDetectList_var2[i] = this->energyDetectList_var[i];
    for (unsigned int i=sz; i<size; i++)
        energyDetectList_var2[i] = 0;
    energyDetectList_arraysize = size;
    delete [] this->energyDetectList_var;
    this->energyDetectList_var = energyDetectList_var2;
}

unsigned int MlmeScan_confirm::getEnergyDetectListArraySize() const
{
    return energyDetectList_arraysize;
}

unsigned char MlmeScan_confirm::getEnergyDetectList(unsigned int k) const
{
    if (k>=energyDetectList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", energyDetectList_arraysize, k);
    return energyDetectList_var[k];
}

void MlmeScan_confirm::setEnergyDetectList(unsigned int k, unsigned char energyDetectList_var)
{
    if (k>=energyDetectList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", energyDetectList_arraysize, k);
    this->energyDetectList_var[k]=energyDetectList_var;
}

void MlmeScan_confirm::setPanDescriptorListArraySize(unsigned int size)
{
    PanDescriptor *panDescriptorList_var2 = (size==0) ? NULL : new PanDescriptor[size];
    unsigned int sz = panDescriptorList_arraysize < size ? panDescriptorList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        panDescriptorList_var2[i] = this->panDescriptorList_var[i];
    panDescriptorList_arraysize = size;
    delete [] this->panDescriptorList_var;
    this->panDescriptorList_var = panDescriptorList_var2;
}

unsigned int MlmeScan_confirm::getPanDescriptorListArraySize() const
{
    return panDescriptorList_arraysize;
}

PanDescriptor& MlmeScan_confirm::getPanDescriptorList(unsigned int k)
{
    if (k>=panDescriptorList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", panDescriptorList_arraysize, k);
    return panDescriptorList_var[k];
}

void MlmeScan_confirm::setPanDescriptorList(unsigned int k, const PanDescriptor& panDescriptorList_var)
{
    if (k>=panDescriptorList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", panDescriptorList_arraysize, k);
    this->panDescriptorList_var[k]=panDescriptorList_var;
}

class MlmeScan_confirmDescriptor : public cClassDescriptor
{
  public:
    MlmeScan_confirmDescriptor();
    virtual ~MlmeScan_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeScan_confirmDescriptor);

MlmeScan_confirmDescriptor::MlmeScan_confirmDescriptor() : cClassDescriptor("MlmeScan_confirm", "MlmeMsg")
{
}

MlmeScan_confirmDescriptor::~MlmeScan_confirmDescriptor()
{
}

bool MlmeScan_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeScan_confirm *>(obj)!=NULL;
}

const char *MlmeScan_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeScan_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int MlmeScan_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISEDITABLE;
        case 5: return FD_ISARRAY | FD_ISEDITABLE;
        case 6: return FD_ISARRAY | FD_ISCOMPOUND;
        default: return 0;
    }
}

const char *MlmeScan_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        case 1: return "scanType";
        case 2: return "channelPage";
        case 3: return "unscannedChannels";
        case 4: return "resultListSize";
        case 5: return "energyDetectList";
        case 6: return "panDescriptorList";
        default: return NULL;
    }
}

const char *MlmeScan_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned char";
        case 2: return "unsigned char";
        case 3: return "unsigned int";
        case 4: return "unsigned int";
        case 5: return "unsigned char";
        case 6: return "PanDescriptor";
        default: return NULL;
    }
}

const char *MlmeScan_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "MacEnum";
            return NULL;
        default: return NULL;
    }
}

int MlmeScan_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeScan_confirm *pp = (MlmeScan_confirm *)object; (void)pp;
    switch (field) {
        case 5: return pp->getEnergyDetectListArraySize();
        case 6: return pp->getPanDescriptorListArraySize();
        default: return 0;
    }
}

bool MlmeScan_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeScan_confirm *pp = (MlmeScan_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getScanType(),resultbuf,bufsize); return true;
        case 2: ulong2string(pp->getChannelPage(),resultbuf,bufsize); return true;
        case 3: ulong2string(pp->getUnscannedChannels(),resultbuf,bufsize); return true;
        case 4: ulong2string(pp->getResultListSize(),resultbuf,bufsize); return true;
        case 5: ulong2string(pp->getEnergyDetectList(i),resultbuf,bufsize); return true;
        case 6: {std::stringstream out; out << pp->getPanDescriptorList(i); opp_strprettytrunc(resultbuf,out.str().c_str(),bufsize-1); return true;}
        default: return false;
    }
}

bool MlmeScan_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeScan_confirm *pp = (MlmeScan_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        case 1: pp->setScanType(string2ulong(value)); return true;
        case 2: pp->setChannelPage(string2ulong(value)); return true;
        case 3: pp->setUnscannedChannels(string2ulong(value)); return true;
        case 4: pp->setResultListSize(string2ulong(value)); return true;
        case 5: pp->setEnergyDetectList(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *MlmeScan_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 6: return "PanDescriptor"; break;
        default: return NULL;
    }
}

void *MlmeScan_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeScan_confirm *pp = (MlmeScan_confirm *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getPanDescriptorList(i)); break;
        default: return NULL;
    }
}

Register_Class(MlmeSet_request);

MlmeSet_request::MlmeSet_request(const char *name, int kind) : MlmeMsg(name,kind)
{
    this->PibAttribute_var = 0;
    this->PibAttributeIndex_var = 0;
    PibAttributeValue_arraysize = 0;
    this->PibAttributeValue_var = 0;
}

MlmeSet_request::MlmeSet_request(const MlmeSet_request& other) : MlmeMsg()
{
    setName(other.getName());
    PibAttributeValue_arraysize = 0;
    this->PibAttributeValue_var = 0;
    operator=(other);
}

MlmeSet_request::~MlmeSet_request()
{
    delete [] PibAttributeValue_var;
}

MlmeSet_request& MlmeSet_request::operator=(const MlmeSet_request& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    this->PibAttribute_var = other.PibAttribute_var;
    this->PibAttributeIndex_var = other.PibAttributeIndex_var;
    delete [] this->PibAttributeValue_var;
    this->PibAttributeValue_var = (other.PibAttributeValue_arraysize==0) ? NULL : new unsigned int[other.PibAttributeValue_arraysize];
    PibAttributeValue_arraysize = other.PibAttributeValue_arraysize;
    for (unsigned int i=0; i<PibAttributeValue_arraysize; i++)
        this->PibAttributeValue_var[i] = other.PibAttributeValue_var[i];
    return *this;
}

void MlmeSet_request::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
    doPacking(b,this->PibAttribute_var);
    doPacking(b,this->PibAttributeIndex_var);
    b->pack(PibAttributeValue_arraysize);
    doPacking(b,this->PibAttributeValue_var,PibAttributeValue_arraysize);
}

void MlmeSet_request::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->PibAttribute_var);
    doUnpacking(b,this->PibAttributeIndex_var);
    delete [] this->PibAttributeValue_var;
    b->unpack(PibAttributeValue_arraysize);
    if (PibAttributeValue_arraysize==0) {
        this->PibAttributeValue_var = 0;
    } else {
        this->PibAttributeValue_var = new unsigned int[PibAttributeValue_arraysize];
        doUnpacking(b,this->PibAttributeValue_var,PibAttributeValue_arraysize);
    }
}

unsigned char MlmeSet_request::getPibAttribute() const
{
    return PibAttribute_var;
}

void MlmeSet_request::setPibAttribute(unsigned char PibAttribute_var)
{
    this->PibAttribute_var = PibAttribute_var;
}

unsigned char MlmeSet_request::getPibAttributeIndex() const
{
    return PibAttributeIndex_var;
}

void MlmeSet_request::setPibAttributeIndex(unsigned char PibAttributeIndex_var)
{
    this->PibAttributeIndex_var = PibAttributeIndex_var;
}

void MlmeSet_request::setPibAttributeValueArraySize(unsigned int size)
{
    unsigned int *PibAttributeValue_var2 = (size==0) ? NULL : new unsigned int[size];
    unsigned int sz = PibAttributeValue_arraysize < size ? PibAttributeValue_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        PibAttributeValue_var2[i] = this->PibAttributeValue_var[i];
    for (unsigned int i=sz; i<size; i++)
        PibAttributeValue_var2[i] = 0;
    PibAttributeValue_arraysize = size;
    delete [] this->PibAttributeValue_var;
    this->PibAttributeValue_var = PibAttributeValue_var2;
}

unsigned int MlmeSet_request::getPibAttributeValueArraySize() const
{
    return PibAttributeValue_arraysize;
}

unsigned int MlmeSet_request::getPibAttributeValue(unsigned int k) const
{
    if (k>=PibAttributeValue_arraysize) throw cRuntimeError("Array of size %d indexed by %d", PibAttributeValue_arraysize, k);
    return PibAttributeValue_var[k];
}

void MlmeSet_request::setPibAttributeValue(unsigned int k, unsigned int PibAttributeValue_var)
{
    if (k>=PibAttributeValue_arraysize) throw cRuntimeError("Array of size %d indexed by %d", PibAttributeValue_arraysize, k);
    this->PibAttributeValue_var[k]=PibAttributeValue_var;
}

class MlmeSet_requestDescriptor : public cClassDescriptor
{
  public:
    MlmeSet_requestDescriptor();
    virtual ~MlmeSet_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeSet_requestDescriptor);

MlmeSet_requestDescriptor::MlmeSet_requestDescriptor() : cClassDescriptor("MlmeSet_request", "MlmeMsg")
{
}

MlmeSet_requestDescriptor::~MlmeSet_requestDescriptor()
{
}

bool MlmeSet_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeSet_request *>(obj)!=NULL;
}

const char *MlmeSet_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeSet_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int MlmeSet_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISARRAY | FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MlmeSet_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "PibAttribute";
        case 1: return "PibAttributeIndex";
        case 2: return "PibAttributeValue";
        default: return NULL;
    }
}

const char *MlmeSet_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned char";
        case 2: return "unsigned int";
        default: return NULL;
    }
}

const char *MlmeSet_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MlmeSet_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeSet_request *pp = (MlmeSet_request *)object; (void)pp;
    switch (field) {
        case 2: return pp->getPibAttributeValueArraySize();
        default: return 0;
    }
}

bool MlmeSet_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeSet_request *pp = (MlmeSet_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getPibAttribute(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getPibAttributeIndex(),resultbuf,bufsize); return true;
        case 2: ulong2string(pp->getPibAttributeValue(i),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MlmeSet_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeSet_request *pp = (MlmeSet_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setPibAttribute(string2ulong(value)); return true;
        case 1: pp->setPibAttributeIndex(string2ulong(value)); return true;
        case 2: pp->setPibAttributeValue(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *MlmeSet_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MlmeSet_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeSet_request *pp = (MlmeSet_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeSet_confirm);

MlmeSet_confirm::MlmeSet_confirm(const char *name, int kind) : MlmeMsg(name,kind)
{
    this->status_var = 0;
    this->PibAttribute_var = 0;
    this->PibAttributeIndex_var = 0;
}

MlmeSet_confirm::MlmeSet_confirm(const MlmeSet_confirm& other) : MlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

MlmeSet_confirm::~MlmeSet_confirm()
{
}

MlmeSet_confirm& MlmeSet_confirm::operator=(const MlmeSet_confirm& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    this->status_var = other.status_var;
    this->PibAttribute_var = other.PibAttribute_var;
    this->PibAttributeIndex_var = other.PibAttributeIndex_var;
    return *this;
}

void MlmeSet_confirm::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
    doPacking(b,this->PibAttribute_var);
    doPacking(b,this->PibAttributeIndex_var);
}

void MlmeSet_confirm::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->PibAttribute_var);
    doUnpacking(b,this->PibAttributeIndex_var);
}

unsigned char MlmeSet_confirm::getStatus() const
{
    return status_var;
}

void MlmeSet_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

unsigned char MlmeSet_confirm::getPibAttribute() const
{
    return PibAttribute_var;
}

void MlmeSet_confirm::setPibAttribute(unsigned char PibAttribute_var)
{
    this->PibAttribute_var = PibAttribute_var;
}

unsigned char MlmeSet_confirm::getPibAttributeIndex() const
{
    return PibAttributeIndex_var;
}

void MlmeSet_confirm::setPibAttributeIndex(unsigned char PibAttributeIndex_var)
{
    this->PibAttributeIndex_var = PibAttributeIndex_var;
}

class MlmeSet_confirmDescriptor : public cClassDescriptor
{
  public:
    MlmeSet_confirmDescriptor();
    virtual ~MlmeSet_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeSet_confirmDescriptor);

MlmeSet_confirmDescriptor::MlmeSet_confirmDescriptor() : cClassDescriptor("MlmeSet_confirm", "MlmeMsg")
{
}

MlmeSet_confirmDescriptor::~MlmeSet_confirmDescriptor()
{
}

bool MlmeSet_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeSet_confirm *>(obj)!=NULL;
}

const char *MlmeSet_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeSet_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int MlmeSet_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MlmeSet_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        case 1: return "PibAttribute";
        case 2: return "PibAttributeIndex";
        default: return NULL;
    }
}

const char *MlmeSet_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned char";
        case 2: return "unsigned char";
        default: return NULL;
    }
}

const char *MlmeSet_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MlmeSet_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeSet_confirm *pp = (MlmeSet_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool MlmeSet_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeSet_confirm *pp = (MlmeSet_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getPibAttribute(),resultbuf,bufsize); return true;
        case 2: ulong2string(pp->getPibAttributeIndex(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MlmeSet_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeSet_confirm *pp = (MlmeSet_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        case 1: pp->setPibAttribute(string2ulong(value)); return true;
        case 2: pp->setPibAttributeIndex(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MlmeSet_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MlmeSet_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeSet_confirm *pp = (MlmeSet_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeStart_request);

MlmeStart_request::MlmeStart_request(const char *name, int kind) : MlmeMsg(name,kind)
{
    this->PanId_var = 0;
    this->logicalChannel_var = 0;
    this->channelPage_var = 0;
    this->startTime_var = 0;
    this->beaconOrder_var = 0;
    this->superframeOrder_var = 0;
    this->panCoordinator_var = 0;
    this->batteryLifeExtension_var = 0;
    this->coordRealignment_var = 0;
    this->coordRealignSecurityLevel_var = 0;
    this->coordRealignKeyIdMode_var = 0;
    coordRealignKeySource_arraysize = 0;
    this->coordRealignKeySource_var = 0;
    this->coordRealignKeyIndex_var = 0;
    this->beaconSecurityLevel_var = 0;
    this->beaconKeyIdMode_var = 0;
    beaconKeySource_arraysize = 0;
    this->beaconKeySource_var = 0;
    this->beaconKeyIndex_var = 0;
}

MlmeStart_request::MlmeStart_request(const MlmeStart_request& other) : MlmeMsg()
{
    setName(other.getName());
    coordRealignKeySource_arraysize = 0;
    this->coordRealignKeySource_var = 0;
    beaconKeySource_arraysize = 0;
    this->beaconKeySource_var = 0;
    operator=(other);
}

MlmeStart_request::~MlmeStart_request()
{
    delete [] coordRealignKeySource_var;
    delete [] beaconKeySource_var;
}

MlmeStart_request& MlmeStart_request::operator=(const MlmeStart_request& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    this->PanId_var = other.PanId_var;
    this->logicalChannel_var = other.logicalChannel_var;
    this->channelPage_var = other.channelPage_var;
    this->startTime_var = other.startTime_var;
    this->beaconOrder_var = other.beaconOrder_var;
    this->superframeOrder_var = other.superframeOrder_var;
    this->panCoordinator_var = other.panCoordinator_var;
    this->batteryLifeExtension_var = other.batteryLifeExtension_var;
    this->coordRealignment_var = other.coordRealignment_var;
    this->coordRealignSecurityLevel_var = other.coordRealignSecurityLevel_var;
    this->coordRealignKeyIdMode_var = other.coordRealignKeyIdMode_var;
    delete [] this->coordRealignKeySource_var;
    this->coordRealignKeySource_var = (other.coordRealignKeySource_arraysize==0) ? NULL : new unsigned char[other.coordRealignKeySource_arraysize];
    coordRealignKeySource_arraysize = other.coordRealignKeySource_arraysize;
    for (unsigned int i=0; i<coordRealignKeySource_arraysize; i++)
        this->coordRealignKeySource_var[i] = other.coordRealignKeySource_var[i];
    this->coordRealignKeyIndex_var = other.coordRealignKeyIndex_var;
    this->beaconSecurityLevel_var = other.beaconSecurityLevel_var;
    this->beaconKeyIdMode_var = other.beaconKeyIdMode_var;
    delete [] this->beaconKeySource_var;
    this->beaconKeySource_var = (other.beaconKeySource_arraysize==0) ? NULL : new unsigned char[other.beaconKeySource_arraysize];
    beaconKeySource_arraysize = other.beaconKeySource_arraysize;
    for (unsigned int i=0; i<beaconKeySource_arraysize; i++)
        this->beaconKeySource_var[i] = other.beaconKeySource_var[i];
    this->beaconKeyIndex_var = other.beaconKeyIndex_var;
    return *this;
}

void MlmeStart_request::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
    doPacking(b,this->PanId_var);
    doPacking(b,this->logicalChannel_var);
    doPacking(b,this->channelPage_var);
    doPacking(b,this->startTime_var);
    doPacking(b,this->beaconOrder_var);
    doPacking(b,this->superframeOrder_var);
    doPacking(b,this->panCoordinator_var);
    doPacking(b,this->batteryLifeExtension_var);
    doPacking(b,this->coordRealignment_var);
    doPacking(b,this->coordRealignSecurityLevel_var);
    doPacking(b,this->coordRealignKeyIdMode_var);
    b->pack(coordRealignKeySource_arraysize);
    doPacking(b,this->coordRealignKeySource_var,coordRealignKeySource_arraysize);
    doPacking(b,this->coordRealignKeyIndex_var);
    doPacking(b,this->beaconSecurityLevel_var);
    doPacking(b,this->beaconKeyIdMode_var);
    b->pack(beaconKeySource_arraysize);
    doPacking(b,this->beaconKeySource_var,beaconKeySource_arraysize);
    doPacking(b,this->beaconKeyIndex_var);
}

void MlmeStart_request::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->PanId_var);
    doUnpacking(b,this->logicalChannel_var);
    doUnpacking(b,this->channelPage_var);
    doUnpacking(b,this->startTime_var);
    doUnpacking(b,this->beaconOrder_var);
    doUnpacking(b,this->superframeOrder_var);
    doUnpacking(b,this->panCoordinator_var);
    doUnpacking(b,this->batteryLifeExtension_var);
    doUnpacking(b,this->coordRealignment_var);
    doUnpacking(b,this->coordRealignSecurityLevel_var);
    doUnpacking(b,this->coordRealignKeyIdMode_var);
    delete [] this->coordRealignKeySource_var;
    b->unpack(coordRealignKeySource_arraysize);
    if (coordRealignKeySource_arraysize==0) {
        this->coordRealignKeySource_var = 0;
    } else {
        this->coordRealignKeySource_var = new unsigned char[coordRealignKeySource_arraysize];
        doUnpacking(b,this->coordRealignKeySource_var,coordRealignKeySource_arraysize);
    }
    doUnpacking(b,this->coordRealignKeyIndex_var);
    doUnpacking(b,this->beaconSecurityLevel_var);
    doUnpacking(b,this->beaconKeyIdMode_var);
    delete [] this->beaconKeySource_var;
    b->unpack(beaconKeySource_arraysize);
    if (beaconKeySource_arraysize==0) {
        this->beaconKeySource_var = 0;
    } else {
        this->beaconKeySource_var = new unsigned char[beaconKeySource_arraysize];
        doUnpacking(b,this->beaconKeySource_var,beaconKeySource_arraysize);
    }
    doUnpacking(b,this->beaconKeyIndex_var);
}

unsigned short MlmeStart_request::getPanId() const
{
    return PanId_var;
}

void MlmeStart_request::setPanId(unsigned short PanId_var)
{
    this->PanId_var = PanId_var;
}

unsigned char MlmeStart_request::getLogicalChannel() const
{
    return logicalChannel_var;
}

void MlmeStart_request::setLogicalChannel(unsigned char logicalChannel_var)
{
    this->logicalChannel_var = logicalChannel_var;
}

unsigned char MlmeStart_request::getChannelPage() const
{
    return channelPage_var;
}

void MlmeStart_request::setChannelPage(unsigned char channelPage_var)
{
    this->channelPage_var = channelPage_var;
}

unsigned int MlmeStart_request::getStartTime() const
{
    return startTime_var;
}

void MlmeStart_request::setStartTime(unsigned int startTime_var)
{
    this->startTime_var = startTime_var;
}

unsigned char MlmeStart_request::getBeaconOrder() const
{
    return beaconOrder_var;
}

void MlmeStart_request::setBeaconOrder(unsigned char beaconOrder_var)
{
    this->beaconOrder_var = beaconOrder_var;
}

unsigned char MlmeStart_request::getSuperframeOrder() const
{
    return superframeOrder_var;
}

void MlmeStart_request::setSuperframeOrder(unsigned char superframeOrder_var)
{
    this->superframeOrder_var = superframeOrder_var;
}

bool MlmeStart_request::getPanCoordinator() const
{
    return panCoordinator_var;
}

void MlmeStart_request::setPanCoordinator(bool panCoordinator_var)
{
    this->panCoordinator_var = panCoordinator_var;
}

bool MlmeStart_request::getBatteryLifeExtension() const
{
    return batteryLifeExtension_var;
}

void MlmeStart_request::setBatteryLifeExtension(bool batteryLifeExtension_var)
{
    this->batteryLifeExtension_var = batteryLifeExtension_var;
}

bool MlmeStart_request::getCoordRealignment() const
{
    return coordRealignment_var;
}

void MlmeStart_request::setCoordRealignment(bool coordRealignment_var)
{
    this->coordRealignment_var = coordRealignment_var;
}

unsigned char MlmeStart_request::getCoordRealignSecurityLevel() const
{
    return coordRealignSecurityLevel_var;
}

void MlmeStart_request::setCoordRealignSecurityLevel(unsigned char coordRealignSecurityLevel_var)
{
    this->coordRealignSecurityLevel_var = coordRealignSecurityLevel_var;
}

unsigned char MlmeStart_request::getCoordRealignKeyIdMode() const
{
    return coordRealignKeyIdMode_var;
}

void MlmeStart_request::setCoordRealignKeyIdMode(unsigned char coordRealignKeyIdMode_var)
{
    this->coordRealignKeyIdMode_var = coordRealignKeyIdMode_var;
}

void MlmeStart_request::setCoordRealignKeySourceArraySize(unsigned int size)
{
    unsigned char *coordRealignKeySource_var2 = (size==0) ? NULL : new unsigned char[size];
    unsigned int sz = coordRealignKeySource_arraysize < size ? coordRealignKeySource_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        coordRealignKeySource_var2[i] = this->coordRealignKeySource_var[i];
    for (unsigned int i=sz; i<size; i++)
        coordRealignKeySource_var2[i] = 0;
    coordRealignKeySource_arraysize = size;
    delete [] this->coordRealignKeySource_var;
    this->coordRealignKeySource_var = coordRealignKeySource_var2;
}

unsigned int MlmeStart_request::getCoordRealignKeySourceArraySize() const
{
    return coordRealignKeySource_arraysize;
}

unsigned char MlmeStart_request::getCoordRealignKeySource(unsigned int k) const
{
    if (k>=coordRealignKeySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", coordRealignKeySource_arraysize, k);
    return coordRealignKeySource_var[k];
}

void MlmeStart_request::setCoordRealignKeySource(unsigned int k, unsigned char coordRealignKeySource_var)
{
    if (k>=coordRealignKeySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", coordRealignKeySource_arraysize, k);
    this->coordRealignKeySource_var[k]=coordRealignKeySource_var;
}

unsigned char MlmeStart_request::getCoordRealignKeyIndex() const
{
    return coordRealignKeyIndex_var;
}

void MlmeStart_request::setCoordRealignKeyIndex(unsigned char coordRealignKeyIndex_var)
{
    this->coordRealignKeyIndex_var = coordRealignKeyIndex_var;
}

unsigned char MlmeStart_request::getBeaconSecurityLevel() const
{
    return beaconSecurityLevel_var;
}

void MlmeStart_request::setBeaconSecurityLevel(unsigned char beaconSecurityLevel_var)
{
    this->beaconSecurityLevel_var = beaconSecurityLevel_var;
}

unsigned char MlmeStart_request::getBeaconKeyIdMode() const
{
    return beaconKeyIdMode_var;
}

void MlmeStart_request::setBeaconKeyIdMode(unsigned char beaconKeyIdMode_var)
{
    this->beaconKeyIdMode_var = beaconKeyIdMode_var;
}

void MlmeStart_request::setBeaconKeySourceArraySize(unsigned int size)
{
    unsigned char *beaconKeySource_var2 = (size==0) ? NULL : new unsigned char[size];
    unsigned int sz = beaconKeySource_arraysize < size ? beaconKeySource_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        beaconKeySource_var2[i] = this->beaconKeySource_var[i];
    for (unsigned int i=sz; i<size; i++)
        beaconKeySource_var2[i] = 0;
    beaconKeySource_arraysize = size;
    delete [] this->beaconKeySource_var;
    this->beaconKeySource_var = beaconKeySource_var2;
}

unsigned int MlmeStart_request::getBeaconKeySourceArraySize() const
{
    return beaconKeySource_arraysize;
}

unsigned char MlmeStart_request::getBeaconKeySource(unsigned int k) const
{
    if (k>=beaconKeySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", beaconKeySource_arraysize, k);
    return beaconKeySource_var[k];
}

void MlmeStart_request::setBeaconKeySource(unsigned int k, unsigned char beaconKeySource_var)
{
    if (k>=beaconKeySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", beaconKeySource_arraysize, k);
    this->beaconKeySource_var[k]=beaconKeySource_var;
}

unsigned char MlmeStart_request::getBeaconKeyIndex() const
{
    return beaconKeyIndex_var;
}

void MlmeStart_request::setBeaconKeyIndex(unsigned char beaconKeyIndex_var)
{
    this->beaconKeyIndex_var = beaconKeyIndex_var;
}

class MlmeStart_requestDescriptor : public cClassDescriptor
{
  public:
    MlmeStart_requestDescriptor();
    virtual ~MlmeStart_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeStart_requestDescriptor);

MlmeStart_requestDescriptor::MlmeStart_requestDescriptor() : cClassDescriptor("MlmeStart_request", "MlmeMsg")
{
}

MlmeStart_requestDescriptor::~MlmeStart_requestDescriptor()
{
}

bool MlmeStart_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeStart_request *>(obj)!=NULL;
}

const char *MlmeStart_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeStart_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 17+basedesc->getFieldCount(object) : 17;
}

unsigned int MlmeStart_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISEDITABLE;
        case 5: return FD_ISEDITABLE;
        case 6: return FD_ISEDITABLE;
        case 7: return FD_ISEDITABLE;
        case 8: return FD_ISEDITABLE;
        case 9: return FD_ISEDITABLE;
        case 10: return FD_ISEDITABLE;
        case 11: return FD_ISARRAY | FD_ISEDITABLE;
        case 12: return FD_ISEDITABLE;
        case 13: return FD_ISEDITABLE;
        case 14: return FD_ISEDITABLE;
        case 15: return FD_ISARRAY | FD_ISEDITABLE;
        case 16: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MlmeStart_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "PanId";
        case 1: return "logicalChannel";
        case 2: return "channelPage";
        case 3: return "startTime";
        case 4: return "beaconOrder";
        case 5: return "superframeOrder";
        case 6: return "panCoordinator";
        case 7: return "batteryLifeExtension";
        case 8: return "coordRealignment";
        case 9: return "coordRealignSecurityLevel";
        case 10: return "coordRealignKeyIdMode";
        case 11: return "coordRealignKeySource";
        case 12: return "coordRealignKeyIndex";
        case 13: return "beaconSecurityLevel";
        case 14: return "beaconKeyIdMode";
        case 15: return "beaconKeySource";
        case 16: return "beaconKeyIndex";
        default: return NULL;
    }
}

const char *MlmeStart_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned short";
        case 1: return "unsigned char";
        case 2: return "unsigned char";
        case 3: return "unsigned int";
        case 4: return "unsigned char";
        case 5: return "unsigned char";
        case 6: return "bool";
        case 7: return "bool";
        case 8: return "bool";
        case 9: return "unsigned char";
        case 10: return "unsigned char";
        case 11: return "unsigned char";
        case 12: return "unsigned char";
        case 13: return "unsigned char";
        case 14: return "unsigned char";
        case 15: return "unsigned char";
        case 16: return "unsigned char";
        default: return NULL;
    }
}

const char *MlmeStart_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MlmeStart_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeStart_request *pp = (MlmeStart_request *)object; (void)pp;
    switch (field) {
        case 11: return pp->getCoordRealignKeySourceArraySize();
        case 15: return pp->getBeaconKeySourceArraySize();
        default: return 0;
    }
}

bool MlmeStart_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeStart_request *pp = (MlmeStart_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getPanId(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getLogicalChannel(),resultbuf,bufsize); return true;
        case 2: ulong2string(pp->getChannelPage(),resultbuf,bufsize); return true;
        case 3: ulong2string(pp->getStartTime(),resultbuf,bufsize); return true;
        case 4: ulong2string(pp->getBeaconOrder(),resultbuf,bufsize); return true;
        case 5: ulong2string(pp->getSuperframeOrder(),resultbuf,bufsize); return true;
        case 6: bool2string(pp->getPanCoordinator(),resultbuf,bufsize); return true;
        case 7: bool2string(pp->getBatteryLifeExtension(),resultbuf,bufsize); return true;
        case 8: bool2string(pp->getCoordRealignment(),resultbuf,bufsize); return true;
        case 9: ulong2string(pp->getCoordRealignSecurityLevel(),resultbuf,bufsize); return true;
        case 10: ulong2string(pp->getCoordRealignKeyIdMode(),resultbuf,bufsize); return true;
        case 11: ulong2string(pp->getCoordRealignKeySource(i),resultbuf,bufsize); return true;
        case 12: ulong2string(pp->getCoordRealignKeyIndex(),resultbuf,bufsize); return true;
        case 13: ulong2string(pp->getBeaconSecurityLevel(),resultbuf,bufsize); return true;
        case 14: ulong2string(pp->getBeaconKeyIdMode(),resultbuf,bufsize); return true;
        case 15: ulong2string(pp->getBeaconKeySource(i),resultbuf,bufsize); return true;
        case 16: ulong2string(pp->getBeaconKeyIndex(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MlmeStart_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeStart_request *pp = (MlmeStart_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setPanId(string2ulong(value)); return true;
        case 1: pp->setLogicalChannel(string2ulong(value)); return true;
        case 2: pp->setChannelPage(string2ulong(value)); return true;
        case 3: pp->setStartTime(string2ulong(value)); return true;
        case 4: pp->setBeaconOrder(string2ulong(value)); return true;
        case 5: pp->setSuperframeOrder(string2ulong(value)); return true;
        case 6: pp->setPanCoordinator(string2bool(value)); return true;
        case 7: pp->setBatteryLifeExtension(string2bool(value)); return true;
        case 8: pp->setCoordRealignment(string2bool(value)); return true;
        case 9: pp->setCoordRealignSecurityLevel(string2ulong(value)); return true;
        case 10: pp->setCoordRealignKeyIdMode(string2ulong(value)); return true;
        case 11: pp->setCoordRealignKeySource(i,string2ulong(value)); return true;
        case 12: pp->setCoordRealignKeyIndex(string2ulong(value)); return true;
        case 13: pp->setBeaconSecurityLevel(string2ulong(value)); return true;
        case 14: pp->setBeaconKeyIdMode(string2ulong(value)); return true;
        case 15: pp->setBeaconKeySource(i,string2ulong(value)); return true;
        case 16: pp->setBeaconKeyIndex(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MlmeStart_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MlmeStart_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeStart_request *pp = (MlmeStart_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeStart_confirm);

MlmeStart_confirm::MlmeStart_confirm(const char *name, int kind) : MlmeMsg(name,kind)
{
    this->status_var = 0;
}

MlmeStart_confirm::MlmeStart_confirm(const MlmeStart_confirm& other) : MlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

MlmeStart_confirm::~MlmeStart_confirm()
{
}

MlmeStart_confirm& MlmeStart_confirm::operator=(const MlmeStart_confirm& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    this->status_var = other.status_var;
    return *this;
}

void MlmeStart_confirm::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
}

void MlmeStart_confirm::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
}

unsigned char MlmeStart_confirm::getStatus() const
{
    return status_var;
}

void MlmeStart_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

class MlmeStart_confirmDescriptor : public cClassDescriptor
{
  public:
    MlmeStart_confirmDescriptor();
    virtual ~MlmeStart_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeStart_confirmDescriptor);

MlmeStart_confirmDescriptor::MlmeStart_confirmDescriptor() : cClassDescriptor("MlmeStart_confirm", "MlmeMsg")
{
}

MlmeStart_confirmDescriptor::~MlmeStart_confirmDescriptor()
{
}

bool MlmeStart_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeStart_confirm *>(obj)!=NULL;
}

const char *MlmeStart_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeStart_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int MlmeStart_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MlmeStart_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        default: return NULL;
    }
}

const char *MlmeStart_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        default: return NULL;
    }
}

const char *MlmeStart_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "MacEnum";
            return NULL;
        default: return NULL;
    }
}

int MlmeStart_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeStart_confirm *pp = (MlmeStart_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool MlmeStart_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeStart_confirm *pp = (MlmeStart_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MlmeStart_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeStart_confirm *pp = (MlmeStart_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MlmeStart_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MlmeStart_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeStart_confirm *pp = (MlmeStart_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeAssociate_request);

MlmeAssociate_request::MlmeAssociate_request(const char *name, int kind) : MlmeMsg(name,kind)
{
    this->logicalChannel_var = 0;
    this->channelPage_var = 0;
    this->coordAddrMode_var = 0;
    this->coordPanId_var = 0;
    this->coordAddress_var = 0;
    this->alternatePanCoordinator_var = 0;
    this->deviceType_var = 0;
    this->powerSource_var = 0;
    this->receiverOnWhenIdle_var = 0;
    this->securityCapability_var = 0;
    this->allocateAddress_var = 0;
    this->securityLevel_var = 0;
    this->keyIdMode_var = 0;
    keySource_arraysize = 0;
    this->keySource_var = 0;
    this->keyIndex_var = 0;
}

MlmeAssociate_request::MlmeAssociate_request(const MlmeAssociate_request& other) : MlmeMsg()
{
    setName(other.getName());
    keySource_arraysize = 0;
    this->keySource_var = 0;
    operator=(other);
}

MlmeAssociate_request::~MlmeAssociate_request()
{
    delete [] keySource_var;
}

MlmeAssociate_request& MlmeAssociate_request::operator=(const MlmeAssociate_request& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    this->logicalChannel_var = other.logicalChannel_var;
    this->channelPage_var = other.channelPage_var;
    this->coordAddrMode_var = other.coordAddrMode_var;
    this->coordPanId_var = other.coordPanId_var;
    this->coordAddress_var = other.coordAddress_var;
    this->alternatePanCoordinator_var = other.alternatePanCoordinator_var;
    this->deviceType_var = other.deviceType_var;
    this->powerSource_var = other.powerSource_var;
    this->receiverOnWhenIdle_var = other.receiverOnWhenIdle_var;
    this->securityCapability_var = other.securityCapability_var;
    this->allocateAddress_var = other.allocateAddress_var;
    this->securityLevel_var = other.securityLevel_var;
    this->keyIdMode_var = other.keyIdMode_var;
    delete [] this->keySource_var;
    this->keySource_var = (other.keySource_arraysize==0) ? NULL : new unsigned char[other.keySource_arraysize];
    keySource_arraysize = other.keySource_arraysize;
    for (unsigned int i=0; i<keySource_arraysize; i++)
        this->keySource_var[i] = other.keySource_var[i];
    this->keyIndex_var = other.keyIndex_var;
    return *this;
}

void MlmeAssociate_request::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
    doPacking(b,this->logicalChannel_var);
    doPacking(b,this->channelPage_var);
    doPacking(b,this->coordAddrMode_var);
    doPacking(b,this->coordPanId_var);
    doPacking(b,this->coordAddress_var);
    doPacking(b,this->alternatePanCoordinator_var);
    doPacking(b,this->deviceType_var);
    doPacking(b,this->powerSource_var);
    doPacking(b,this->receiverOnWhenIdle_var);
    doPacking(b,this->securityCapability_var);
    doPacking(b,this->allocateAddress_var);
    doPacking(b,this->securityLevel_var);
    doPacking(b,this->keyIdMode_var);
    b->pack(keySource_arraysize);
    doPacking(b,this->keySource_var,keySource_arraysize);
    doPacking(b,this->keyIndex_var);
}

void MlmeAssociate_request::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->logicalChannel_var);
    doUnpacking(b,this->channelPage_var);
    doUnpacking(b,this->coordAddrMode_var);
    doUnpacking(b,this->coordPanId_var);
    doUnpacking(b,this->coordAddress_var);
    doUnpacking(b,this->alternatePanCoordinator_var);
    doUnpacking(b,this->deviceType_var);
    doUnpacking(b,this->powerSource_var);
    doUnpacking(b,this->receiverOnWhenIdle_var);
    doUnpacking(b,this->securityCapability_var);
    doUnpacking(b,this->allocateAddress_var);
    doUnpacking(b,this->securityLevel_var);
    doUnpacking(b,this->keyIdMode_var);
    delete [] this->keySource_var;
    b->unpack(keySource_arraysize);
    if (keySource_arraysize==0) {
        this->keySource_var = 0;
    } else {
        this->keySource_var = new unsigned char[keySource_arraysize];
        doUnpacking(b,this->keySource_var,keySource_arraysize);
    }
    doUnpacking(b,this->keyIndex_var);
}

unsigned char MlmeAssociate_request::getLogicalChannel() const
{
    return logicalChannel_var;
}

void MlmeAssociate_request::setLogicalChannel(unsigned char logicalChannel_var)
{
    this->logicalChannel_var = logicalChannel_var;
}

unsigned char MlmeAssociate_request::getChannelPage() const
{
    return channelPage_var;
}

void MlmeAssociate_request::setChannelPage(unsigned char channelPage_var)
{
    this->channelPage_var = channelPage_var;
}

unsigned char MlmeAssociate_request::getCoordAddrMode() const
{
    return coordAddrMode_var;
}

void MlmeAssociate_request::setCoordAddrMode(unsigned char coordAddrMode_var)
{
    this->coordAddrMode_var = coordAddrMode_var;
}

unsigned short MlmeAssociate_request::getCoordPanId() const
{
    return coordPanId_var;
}

void MlmeAssociate_request::setCoordPanId(unsigned short coordPanId_var)
{
    this->coordPanId_var = coordPanId_var;
}

unsigned long MlmeAssociate_request::getCoordAddress() const
{
    return coordAddress_var;
}

void MlmeAssociate_request::setCoordAddress(unsigned long coordAddress_var)
{
    this->coordAddress_var = coordAddress_var;
}

bool MlmeAssociate_request::getAlternatePanCoordinator() const
{
    return alternatePanCoordinator_var;
}

void MlmeAssociate_request::setAlternatePanCoordinator(bool alternatePanCoordinator_var)
{
    this->alternatePanCoordinator_var = alternatePanCoordinator_var;
}

bool MlmeAssociate_request::getDeviceType() const
{
    return deviceType_var;
}

void MlmeAssociate_request::setDeviceType(bool deviceType_var)
{
    this->deviceType_var = deviceType_var;
}

bool MlmeAssociate_request::getPowerSource() const
{
    return powerSource_var;
}

void MlmeAssociate_request::setPowerSource(bool powerSource_var)
{
    this->powerSource_var = powerSource_var;
}

bool MlmeAssociate_request::getReceiverOnWhenIdle() const
{
    return receiverOnWhenIdle_var;
}

void MlmeAssociate_request::setReceiverOnWhenIdle(bool receiverOnWhenIdle_var)
{
    this->receiverOnWhenIdle_var = receiverOnWhenIdle_var;
}

bool MlmeAssociate_request::getSecurityCapability() const
{
    return securityCapability_var;
}

void MlmeAssociate_request::setSecurityCapability(bool securityCapability_var)
{
    this->securityCapability_var = securityCapability_var;
}

bool MlmeAssociate_request::getAllocateAddress() const
{
    return allocateAddress_var;
}

void MlmeAssociate_request::setAllocateAddress(bool allocateAddress_var)
{
    this->allocateAddress_var = allocateAddress_var;
}

unsigned char MlmeAssociate_request::getSecurityLevel() const
{
    return securityLevel_var;
}

void MlmeAssociate_request::setSecurityLevel(unsigned char securityLevel_var)
{
    this->securityLevel_var = securityLevel_var;
}

unsigned char MlmeAssociate_request::getKeyIdMode() const
{
    return keyIdMode_var;
}

void MlmeAssociate_request::setKeyIdMode(unsigned char keyIdMode_var)
{
    this->keyIdMode_var = keyIdMode_var;
}

void MlmeAssociate_request::setKeySourceArraySize(unsigned int size)
{
    unsigned char *keySource_var2 = (size==0) ? NULL : new unsigned char[size];
    unsigned int sz = keySource_arraysize < size ? keySource_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        keySource_var2[i] = this->keySource_var[i];
    for (unsigned int i=sz; i<size; i++)
        keySource_var2[i] = 0;
    keySource_arraysize = size;
    delete [] this->keySource_var;
    this->keySource_var = keySource_var2;
}

unsigned int MlmeAssociate_request::getKeySourceArraySize() const
{
    return keySource_arraysize;
}

unsigned char MlmeAssociate_request::getKeySource(unsigned int k) const
{
    if (k>=keySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", keySource_arraysize, k);
    return keySource_var[k];
}

void MlmeAssociate_request::setKeySource(unsigned int k, unsigned char keySource_var)
{
    if (k>=keySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", keySource_arraysize, k);
    this->keySource_var[k]=keySource_var;
}

unsigned char MlmeAssociate_request::getKeyIndex() const
{
    return keyIndex_var;
}

void MlmeAssociate_request::setKeyIndex(unsigned char keyIndex_var)
{
    this->keyIndex_var = keyIndex_var;
}

class MlmeAssociate_requestDescriptor : public cClassDescriptor
{
  public:
    MlmeAssociate_requestDescriptor();
    virtual ~MlmeAssociate_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeAssociate_requestDescriptor);

MlmeAssociate_requestDescriptor::MlmeAssociate_requestDescriptor() : cClassDescriptor("MlmeAssociate_request", "MlmeMsg")
{
}

MlmeAssociate_requestDescriptor::~MlmeAssociate_requestDescriptor()
{
}

bool MlmeAssociate_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeAssociate_request *>(obj)!=NULL;
}

const char *MlmeAssociate_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeAssociate_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount(object) : 15;
}

unsigned int MlmeAssociate_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISEDITABLE;
        case 5: return FD_ISEDITABLE;
        case 6: return FD_ISEDITABLE;
        case 7: return FD_ISEDITABLE;
        case 8: return FD_ISEDITABLE;
        case 9: return FD_ISEDITABLE;
        case 10: return FD_ISEDITABLE;
        case 11: return FD_ISEDITABLE;
        case 12: return FD_ISEDITABLE;
        case 13: return FD_ISARRAY | FD_ISEDITABLE;
        case 14: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MlmeAssociate_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "logicalChannel";
        case 1: return "channelPage";
        case 2: return "coordAddrMode";
        case 3: return "coordPanId";
        case 4: return "coordAddress";
        case 5: return "alternatePanCoordinator";
        case 6: return "deviceType";
        case 7: return "powerSource";
        case 8: return "receiverOnWhenIdle";
        case 9: return "securityCapability";
        case 10: return "allocateAddress";
        case 11: return "securityLevel";
        case 12: return "keyIdMode";
        case 13: return "keySource";
        case 14: return "keyIndex";
        default: return NULL;
    }
}

const char *MlmeAssociate_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned char";
        case 2: return "unsigned char";
        case 3: return "unsigned short";
        case 4: return "unsigned long";
        case 5: return "bool";
        case 6: return "bool";
        case 7: return "bool";
        case 8: return "bool";
        case 9: return "bool";
        case 10: return "bool";
        case 11: return "unsigned char";
        case 12: return "unsigned char";
        case 13: return "unsigned char";
        case 14: return "unsigned char";
        default: return NULL;
    }
}

const char *MlmeAssociate_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MlmeAssociate_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_request *pp = (MlmeAssociate_request *)object; (void)pp;
    switch (field) {
        case 13: return pp->getKeySourceArraySize();
        default: return 0;
    }
}

bool MlmeAssociate_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_request *pp = (MlmeAssociate_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getLogicalChannel(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getChannelPage(),resultbuf,bufsize); return true;
        case 2: ulong2string(pp->getCoordAddrMode(),resultbuf,bufsize); return true;
        case 3: ulong2string(pp->getCoordPanId(),resultbuf,bufsize); return true;
        case 4: ulong2string(pp->getCoordAddress(),resultbuf,bufsize); return true;
        case 5: bool2string(pp->getAlternatePanCoordinator(),resultbuf,bufsize); return true;
        case 6: bool2string(pp->getDeviceType(),resultbuf,bufsize); return true;
        case 7: bool2string(pp->getPowerSource(),resultbuf,bufsize); return true;
        case 8: bool2string(pp->getReceiverOnWhenIdle(),resultbuf,bufsize); return true;
        case 9: bool2string(pp->getSecurityCapability(),resultbuf,bufsize); return true;
        case 10: bool2string(pp->getAllocateAddress(),resultbuf,bufsize); return true;
        case 11: ulong2string(pp->getSecurityLevel(),resultbuf,bufsize); return true;
        case 12: ulong2string(pp->getKeyIdMode(),resultbuf,bufsize); return true;
        case 13: ulong2string(pp->getKeySource(i),resultbuf,bufsize); return true;
        case 14: ulong2string(pp->getKeyIndex(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MlmeAssociate_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_request *pp = (MlmeAssociate_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setLogicalChannel(string2ulong(value)); return true;
        case 1: pp->setChannelPage(string2ulong(value)); return true;
        case 2: pp->setCoordAddrMode(string2ulong(value)); return true;
        case 3: pp->setCoordPanId(string2ulong(value)); return true;
        case 4: pp->setCoordAddress(string2ulong(value)); return true;
        case 5: pp->setAlternatePanCoordinator(string2bool(value)); return true;
        case 6: pp->setDeviceType(string2bool(value)); return true;
        case 7: pp->setPowerSource(string2bool(value)); return true;
        case 8: pp->setReceiverOnWhenIdle(string2bool(value)); return true;
        case 9: pp->setSecurityCapability(string2bool(value)); return true;
        case 10: pp->setAllocateAddress(string2bool(value)); return true;
        case 11: pp->setSecurityLevel(string2ulong(value)); return true;
        case 12: pp->setKeyIdMode(string2ulong(value)); return true;
        case 13: pp->setKeySource(i,string2ulong(value)); return true;
        case 14: pp->setKeyIndex(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MlmeAssociate_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MlmeAssociate_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_request *pp = (MlmeAssociate_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeAssociate_confirm);

MlmeAssociate_confirm::MlmeAssociate_confirm(const char *name, int kind) : MlmeMsg(name,kind)
{
}

MlmeAssociate_confirm::MlmeAssociate_confirm(const MlmeAssociate_confirm& other) : MlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

MlmeAssociate_confirm::~MlmeAssociate_confirm()
{
}

MlmeAssociate_confirm& MlmeAssociate_confirm::operator=(const MlmeAssociate_confirm& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    return *this;
}

void MlmeAssociate_confirm::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
}

void MlmeAssociate_confirm::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
}

class MlmeAssociate_confirmDescriptor : public cClassDescriptor
{
  public:
    MlmeAssociate_confirmDescriptor();
    virtual ~MlmeAssociate_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeAssociate_confirmDescriptor);

MlmeAssociate_confirmDescriptor::MlmeAssociate_confirmDescriptor() : cClassDescriptor("MlmeAssociate_confirm", "MlmeMsg")
{
}

MlmeAssociate_confirmDescriptor::~MlmeAssociate_confirmDescriptor()
{
}

bool MlmeAssociate_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeAssociate_confirm *>(obj)!=NULL;
}

const char *MlmeAssociate_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeAssociate_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int MlmeAssociate_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return 0;
    }
}

const char *MlmeAssociate_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *MlmeAssociate_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *MlmeAssociate_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MlmeAssociate_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_confirm *pp = (MlmeAssociate_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool MlmeAssociate_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_confirm *pp = (MlmeAssociate_confirm *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

bool MlmeAssociate_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_confirm *pp = (MlmeAssociate_confirm *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MlmeAssociate_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MlmeAssociate_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_confirm *pp = (MlmeAssociate_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeAssociate_indication);

MlmeAssociate_indication::MlmeAssociate_indication(const char *name, int kind) : MlmeMsg(name,kind)
{
    this->deviceAddress_var = 0;
    this->alternatePanCoordinator_var = 0;
    this->deviceType_var = 0;
    this->powerSource_var = 0;
    this->receiverOnWhenIdle_var = 0;
    this->securityCapability_var = 0;
    this->allocateAddress_var = 0;
    this->securityLevel_var = 0;
    this->keyIdMode_var = 0;
    keySource_arraysize = 0;
    this->keySource_var = 0;
    this->keyIndex_var = 0;
}

MlmeAssociate_indication::MlmeAssociate_indication(const MlmeAssociate_indication& other) : MlmeMsg()
{
    setName(other.getName());
    keySource_arraysize = 0;
    this->keySource_var = 0;
    operator=(other);
}

MlmeAssociate_indication::~MlmeAssociate_indication()
{
    delete [] keySource_var;
}

MlmeAssociate_indication& MlmeAssociate_indication::operator=(const MlmeAssociate_indication& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    this->deviceAddress_var = other.deviceAddress_var;
    this->alternatePanCoordinator_var = other.alternatePanCoordinator_var;
    this->deviceType_var = other.deviceType_var;
    this->powerSource_var = other.powerSource_var;
    this->receiverOnWhenIdle_var = other.receiverOnWhenIdle_var;
    this->securityCapability_var = other.securityCapability_var;
    this->allocateAddress_var = other.allocateAddress_var;
    this->securityLevel_var = other.securityLevel_var;
    this->keyIdMode_var = other.keyIdMode_var;
    delete [] this->keySource_var;
    this->keySource_var = (other.keySource_arraysize==0) ? NULL : new unsigned char[other.keySource_arraysize];
    keySource_arraysize = other.keySource_arraysize;
    for (unsigned int i=0; i<keySource_arraysize; i++)
        this->keySource_var[i] = other.keySource_var[i];
    this->keyIndex_var = other.keyIndex_var;
    return *this;
}

void MlmeAssociate_indication::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
    doPacking(b,this->deviceAddress_var);
    doPacking(b,this->alternatePanCoordinator_var);
    doPacking(b,this->deviceType_var);
    doPacking(b,this->powerSource_var);
    doPacking(b,this->receiverOnWhenIdle_var);
    doPacking(b,this->securityCapability_var);
    doPacking(b,this->allocateAddress_var);
    doPacking(b,this->securityLevel_var);
    doPacking(b,this->keyIdMode_var);
    b->pack(keySource_arraysize);
    doPacking(b,this->keySource_var,keySource_arraysize);
    doPacking(b,this->keyIndex_var);
}

void MlmeAssociate_indication::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->deviceAddress_var);
    doUnpacking(b,this->alternatePanCoordinator_var);
    doUnpacking(b,this->deviceType_var);
    doUnpacking(b,this->powerSource_var);
    doUnpacking(b,this->receiverOnWhenIdle_var);
    doUnpacking(b,this->securityCapability_var);
    doUnpacking(b,this->allocateAddress_var);
    doUnpacking(b,this->securityLevel_var);
    doUnpacking(b,this->keyIdMode_var);
    delete [] this->keySource_var;
    b->unpack(keySource_arraysize);
    if (keySource_arraysize==0) {
        this->keySource_var = 0;
    } else {
        this->keySource_var = new unsigned char[keySource_arraysize];
        doUnpacking(b,this->keySource_var,keySource_arraysize);
    }
    doUnpacking(b,this->keyIndex_var);
}

unsigned long MlmeAssociate_indication::getDeviceAddress() const
{
    return deviceAddress_var;
}

void MlmeAssociate_indication::setDeviceAddress(unsigned long deviceAddress_var)
{
    this->deviceAddress_var = deviceAddress_var;
}

bool MlmeAssociate_indication::getAlternatePanCoordinator() const
{
    return alternatePanCoordinator_var;
}

void MlmeAssociate_indication::setAlternatePanCoordinator(bool alternatePanCoordinator_var)
{
    this->alternatePanCoordinator_var = alternatePanCoordinator_var;
}

bool MlmeAssociate_indication::getDeviceType() const
{
    return deviceType_var;
}

void MlmeAssociate_indication::setDeviceType(bool deviceType_var)
{
    this->deviceType_var = deviceType_var;
}

bool MlmeAssociate_indication::getPowerSource() const
{
    return powerSource_var;
}

void MlmeAssociate_indication::setPowerSource(bool powerSource_var)
{
    this->powerSource_var = powerSource_var;
}

bool MlmeAssociate_indication::getReceiverOnWhenIdle() const
{
    return receiverOnWhenIdle_var;
}

void MlmeAssociate_indication::setReceiverOnWhenIdle(bool receiverOnWhenIdle_var)
{
    this->receiverOnWhenIdle_var = receiverOnWhenIdle_var;
}

bool MlmeAssociate_indication::getSecurityCapability() const
{
    return securityCapability_var;
}

void MlmeAssociate_indication::setSecurityCapability(bool securityCapability_var)
{
    this->securityCapability_var = securityCapability_var;
}

bool MlmeAssociate_indication::getAllocateAddress() const
{
    return allocateAddress_var;
}

void MlmeAssociate_indication::setAllocateAddress(bool allocateAddress_var)
{
    this->allocateAddress_var = allocateAddress_var;
}

unsigned char MlmeAssociate_indication::getSecurityLevel() const
{
    return securityLevel_var;
}

void MlmeAssociate_indication::setSecurityLevel(unsigned char securityLevel_var)
{
    this->securityLevel_var = securityLevel_var;
}

unsigned char MlmeAssociate_indication::getKeyIdMode() const
{
    return keyIdMode_var;
}

void MlmeAssociate_indication::setKeyIdMode(unsigned char keyIdMode_var)
{
    this->keyIdMode_var = keyIdMode_var;
}

void MlmeAssociate_indication::setKeySourceArraySize(unsigned int size)
{
    unsigned char *keySource_var2 = (size==0) ? NULL : new unsigned char[size];
    unsigned int sz = keySource_arraysize < size ? keySource_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        keySource_var2[i] = this->keySource_var[i];
    for (unsigned int i=sz; i<size; i++)
        keySource_var2[i] = 0;
    keySource_arraysize = size;
    delete [] this->keySource_var;
    this->keySource_var = keySource_var2;
}

unsigned int MlmeAssociate_indication::getKeySourceArraySize() const
{
    return keySource_arraysize;
}

unsigned char MlmeAssociate_indication::getKeySource(unsigned int k) const
{
    if (k>=keySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", keySource_arraysize, k);
    return keySource_var[k];
}

void MlmeAssociate_indication::setKeySource(unsigned int k, unsigned char keySource_var)
{
    if (k>=keySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", keySource_arraysize, k);
    this->keySource_var[k]=keySource_var;
}

unsigned char MlmeAssociate_indication::getKeyIndex() const
{
    return keyIndex_var;
}

void MlmeAssociate_indication::setKeyIndex(unsigned char keyIndex_var)
{
    this->keyIndex_var = keyIndex_var;
}

class MlmeAssociate_indicationDescriptor : public cClassDescriptor
{
  public:
    MlmeAssociate_indicationDescriptor();
    virtual ~MlmeAssociate_indicationDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeAssociate_indicationDescriptor);

MlmeAssociate_indicationDescriptor::MlmeAssociate_indicationDescriptor() : cClassDescriptor("MlmeAssociate_indication", "MlmeMsg")
{
}

MlmeAssociate_indicationDescriptor::~MlmeAssociate_indicationDescriptor()
{
}

bool MlmeAssociate_indicationDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeAssociate_indication *>(obj)!=NULL;
}

const char *MlmeAssociate_indicationDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeAssociate_indicationDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int MlmeAssociate_indicationDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISEDITABLE;
        case 5: return FD_ISEDITABLE;
        case 6: return FD_ISEDITABLE;
        case 7: return FD_ISEDITABLE;
        case 8: return FD_ISEDITABLE;
        case 9: return FD_ISARRAY | FD_ISEDITABLE;
        case 10: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MlmeAssociate_indicationDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "deviceAddress";
        case 1: return "alternatePanCoordinator";
        case 2: return "deviceType";
        case 3: return "powerSource";
        case 4: return "receiverOnWhenIdle";
        case 5: return "securityCapability";
        case 6: return "allocateAddress";
        case 7: return "securityLevel";
        case 8: return "keyIdMode";
        case 9: return "keySource";
        case 10: return "keyIndex";
        default: return NULL;
    }
}

const char *MlmeAssociate_indicationDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned long";
        case 1: return "bool";
        case 2: return "bool";
        case 3: return "bool";
        case 4: return "bool";
        case 5: return "bool";
        case 6: return "bool";
        case 7: return "unsigned char";
        case 8: return "unsigned char";
        case 9: return "unsigned char";
        case 10: return "unsigned char";
        default: return NULL;
    }
}

const char *MlmeAssociate_indicationDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MlmeAssociate_indicationDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_indication *pp = (MlmeAssociate_indication *)object; (void)pp;
    switch (field) {
        case 9: return pp->getKeySourceArraySize();
        default: return 0;
    }
}

bool MlmeAssociate_indicationDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_indication *pp = (MlmeAssociate_indication *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getDeviceAddress(),resultbuf,bufsize); return true;
        case 1: bool2string(pp->getAlternatePanCoordinator(),resultbuf,bufsize); return true;
        case 2: bool2string(pp->getDeviceType(),resultbuf,bufsize); return true;
        case 3: bool2string(pp->getPowerSource(),resultbuf,bufsize); return true;
        case 4: bool2string(pp->getReceiverOnWhenIdle(),resultbuf,bufsize); return true;
        case 5: bool2string(pp->getSecurityCapability(),resultbuf,bufsize); return true;
        case 6: bool2string(pp->getAllocateAddress(),resultbuf,bufsize); return true;
        case 7: ulong2string(pp->getSecurityLevel(),resultbuf,bufsize); return true;
        case 8: ulong2string(pp->getKeyIdMode(),resultbuf,bufsize); return true;
        case 9: ulong2string(pp->getKeySource(i),resultbuf,bufsize); return true;
        case 10: ulong2string(pp->getKeyIndex(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MlmeAssociate_indicationDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_indication *pp = (MlmeAssociate_indication *)object; (void)pp;
    switch (field) {
        case 0: pp->setDeviceAddress(string2ulong(value)); return true;
        case 1: pp->setAlternatePanCoordinator(string2bool(value)); return true;
        case 2: pp->setDeviceType(string2bool(value)); return true;
        case 3: pp->setPowerSource(string2bool(value)); return true;
        case 4: pp->setReceiverOnWhenIdle(string2bool(value)); return true;
        case 5: pp->setSecurityCapability(string2bool(value)); return true;
        case 6: pp->setAllocateAddress(string2bool(value)); return true;
        case 7: pp->setSecurityLevel(string2ulong(value)); return true;
        case 8: pp->setKeyIdMode(string2ulong(value)); return true;
        case 9: pp->setKeySource(i,string2ulong(value)); return true;
        case 10: pp->setKeyIndex(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MlmeAssociate_indicationDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MlmeAssociate_indicationDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_indication *pp = (MlmeAssociate_indication *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeAssociate_response);

MlmeAssociate_response::MlmeAssociate_response(const char *name, int kind) : MlmeMsg(name,kind)
{
    this->deviceAddress_var = 0;
    this->assocShortAddress_var = 0;
    this->status_var = 0;
    this->securityLevel_var = 0;
    this->keyIdMode_var = 0;
    keySource_arraysize = 0;
    this->keySource_var = 0;
    this->keyIndex_var = 0;
}

MlmeAssociate_response::MlmeAssociate_response(const MlmeAssociate_response& other) : MlmeMsg()
{
    setName(other.getName());
    keySource_arraysize = 0;
    this->keySource_var = 0;
    operator=(other);
}

MlmeAssociate_response::~MlmeAssociate_response()
{
    delete [] keySource_var;
}

MlmeAssociate_response& MlmeAssociate_response::operator=(const MlmeAssociate_response& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    this->deviceAddress_var = other.deviceAddress_var;
    this->assocShortAddress_var = other.assocShortAddress_var;
    this->status_var = other.status_var;
    this->securityLevel_var = other.securityLevel_var;
    this->keyIdMode_var = other.keyIdMode_var;
    delete [] this->keySource_var;
    this->keySource_var = (other.keySource_arraysize==0) ? NULL : new unsigned char[other.keySource_arraysize];
    keySource_arraysize = other.keySource_arraysize;
    for (unsigned int i=0; i<keySource_arraysize; i++)
        this->keySource_var[i] = other.keySource_var[i];
    this->keyIndex_var = other.keyIndex_var;
    return *this;
}

void MlmeAssociate_response::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
    doPacking(b,this->deviceAddress_var);
    doPacking(b,this->assocShortAddress_var);
    doPacking(b,this->status_var);
    doPacking(b,this->securityLevel_var);
    doPacking(b,this->keyIdMode_var);
    b->pack(keySource_arraysize);
    doPacking(b,this->keySource_var,keySource_arraysize);
    doPacking(b,this->keyIndex_var);
}

void MlmeAssociate_response::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->deviceAddress_var);
    doUnpacking(b,this->assocShortAddress_var);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->securityLevel_var);
    doUnpacking(b,this->keyIdMode_var);
    delete [] this->keySource_var;
    b->unpack(keySource_arraysize);
    if (keySource_arraysize==0) {
        this->keySource_var = 0;
    } else {
        this->keySource_var = new unsigned char[keySource_arraysize];
        doUnpacking(b,this->keySource_var,keySource_arraysize);
    }
    doUnpacking(b,this->keyIndex_var);
}

unsigned long MlmeAssociate_response::getDeviceAddress() const
{
    return deviceAddress_var;
}

void MlmeAssociate_response::setDeviceAddress(unsigned long deviceAddress_var)
{
    this->deviceAddress_var = deviceAddress_var;
}

unsigned short MlmeAssociate_response::getAssocShortAddress() const
{
    return assocShortAddress_var;
}

void MlmeAssociate_response::setAssocShortAddress(unsigned short assocShortAddress_var)
{
    this->assocShortAddress_var = assocShortAddress_var;
}

unsigned char MlmeAssociate_response::getStatus() const
{
    return status_var;
}

void MlmeAssociate_response::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

unsigned char MlmeAssociate_response::getSecurityLevel() const
{
    return securityLevel_var;
}

void MlmeAssociate_response::setSecurityLevel(unsigned char securityLevel_var)
{
    this->securityLevel_var = securityLevel_var;
}

unsigned char MlmeAssociate_response::getKeyIdMode() const
{
    return keyIdMode_var;
}

void MlmeAssociate_response::setKeyIdMode(unsigned char keyIdMode_var)
{
    this->keyIdMode_var = keyIdMode_var;
}

void MlmeAssociate_response::setKeySourceArraySize(unsigned int size)
{
    unsigned char *keySource_var2 = (size==0) ? NULL : new unsigned char[size];
    unsigned int sz = keySource_arraysize < size ? keySource_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        keySource_var2[i] = this->keySource_var[i];
    for (unsigned int i=sz; i<size; i++)
        keySource_var2[i] = 0;
    keySource_arraysize = size;
    delete [] this->keySource_var;
    this->keySource_var = keySource_var2;
}

unsigned int MlmeAssociate_response::getKeySourceArraySize() const
{
    return keySource_arraysize;
}

unsigned char MlmeAssociate_response::getKeySource(unsigned int k) const
{
    if (k>=keySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", keySource_arraysize, k);
    return keySource_var[k];
}

void MlmeAssociate_response::setKeySource(unsigned int k, unsigned char keySource_var)
{
    if (k>=keySource_arraysize) throw cRuntimeError("Array of size %d indexed by %d", keySource_arraysize, k);
    this->keySource_var[k]=keySource_var;
}

unsigned char MlmeAssociate_response::getKeyIndex() const
{
    return keyIndex_var;
}

void MlmeAssociate_response::setKeyIndex(unsigned char keyIndex_var)
{
    this->keyIndex_var = keyIndex_var;
}

class MlmeAssociate_responseDescriptor : public cClassDescriptor
{
  public:
    MlmeAssociate_responseDescriptor();
    virtual ~MlmeAssociate_responseDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeAssociate_responseDescriptor);

MlmeAssociate_responseDescriptor::MlmeAssociate_responseDescriptor() : cClassDescriptor("MlmeAssociate_response", "MlmeMsg")
{
}

MlmeAssociate_responseDescriptor::~MlmeAssociate_responseDescriptor()
{
}

bool MlmeAssociate_responseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeAssociate_response *>(obj)!=NULL;
}

const char *MlmeAssociate_responseDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeAssociate_responseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int MlmeAssociate_responseDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISEDITABLE;
        case 5: return FD_ISARRAY | FD_ISEDITABLE;
        case 6: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MlmeAssociate_responseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "deviceAddress";
        case 1: return "assocShortAddress";
        case 2: return "status";
        case 3: return "securityLevel";
        case 4: return "keyIdMode";
        case 5: return "keySource";
        case 6: return "keyIndex";
        default: return NULL;
    }
}

const char *MlmeAssociate_responseDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned long";
        case 1: return "unsigned short";
        case 2: return "unsigned char";
        case 3: return "unsigned char";
        case 4: return "unsigned char";
        case 5: return "unsigned char";
        case 6: return "unsigned char";
        default: return NULL;
    }
}

const char *MlmeAssociate_responseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MlmeAssociate_responseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_response *pp = (MlmeAssociate_response *)object; (void)pp;
    switch (field) {
        case 5: return pp->getKeySourceArraySize();
        default: return 0;
    }
}

bool MlmeAssociate_responseDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_response *pp = (MlmeAssociate_response *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getDeviceAddress(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getAssocShortAddress(),resultbuf,bufsize); return true;
        case 2: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        case 3: ulong2string(pp->getSecurityLevel(),resultbuf,bufsize); return true;
        case 4: ulong2string(pp->getKeyIdMode(),resultbuf,bufsize); return true;
        case 5: ulong2string(pp->getKeySource(i),resultbuf,bufsize); return true;
        case 6: ulong2string(pp->getKeyIndex(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MlmeAssociate_responseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_response *pp = (MlmeAssociate_response *)object; (void)pp;
    switch (field) {
        case 0: pp->setDeviceAddress(string2ulong(value)); return true;
        case 1: pp->setAssocShortAddress(string2ulong(value)); return true;
        case 2: pp->setStatus(string2ulong(value)); return true;
        case 3: pp->setSecurityLevel(string2ulong(value)); return true;
        case 4: pp->setKeyIdMode(string2ulong(value)); return true;
        case 5: pp->setKeySource(i,string2ulong(value)); return true;
        case 6: pp->setKeyIndex(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MlmeAssociate_responseDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MlmeAssociate_responseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeAssociate_response *pp = (MlmeAssociate_response *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MlmeBeaconNotify_indication);

MlmeBeaconNotify_indication::MlmeBeaconNotify_indication(const char *name, int kind) : MlmeMsg(name,kind)
{
    this->bsn_var = 0;
    this->numberOfShortAddressesPending_var = 0;
    this->numberOfExtendedAddressesPending_var = 0;
    addressList_arraysize = 0;
    this->addressList_var = 0;
    this->sduLength_var = 0;
    sdu_arraysize = 0;
    this->sdu_var = 0;
}

MlmeBeaconNotify_indication::MlmeBeaconNotify_indication(const MlmeBeaconNotify_indication& other) : MlmeMsg()
{
    setName(other.getName());
    addressList_arraysize = 0;
    this->addressList_var = 0;
    sdu_arraysize = 0;
    this->sdu_var = 0;
    operator=(other);
}

MlmeBeaconNotify_indication::~MlmeBeaconNotify_indication()
{
    delete [] addressList_var;
    delete [] sdu_var;
}

MlmeBeaconNotify_indication& MlmeBeaconNotify_indication::operator=(const MlmeBeaconNotify_indication& other)
{
    if (this==&other) return *this;
    MlmeMsg::operator=(other);
    this->bsn_var = other.bsn_var;
    this->panDescriptor_var = other.panDescriptor_var;
    this->numberOfShortAddressesPending_var = other.numberOfShortAddressesPending_var;
    this->numberOfExtendedAddressesPending_var = other.numberOfExtendedAddressesPending_var;
    delete [] this->addressList_var;
    this->addressList_var = (other.addressList_arraysize==0) ? NULL : new unsigned long[other.addressList_arraysize];
    addressList_arraysize = other.addressList_arraysize;
    for (unsigned int i=0; i<addressList_arraysize; i++)
        this->addressList_var[i] = other.addressList_var[i];
    this->sduLength_var = other.sduLength_var;
    delete [] this->sdu_var;
    this->sdu_var = (other.sdu_arraysize==0) ? NULL : new unsigned int[other.sdu_arraysize];
    sdu_arraysize = other.sdu_arraysize;
    for (unsigned int i=0; i<sdu_arraysize; i++)
        this->sdu_var[i] = other.sdu_var[i];
    return *this;
}

void MlmeBeaconNotify_indication::parsimPack(cCommBuffer *b)
{
    MlmeMsg::parsimPack(b);
    doPacking(b,this->bsn_var);
    doPacking(b,this->panDescriptor_var);
    doPacking(b,this->numberOfShortAddressesPending_var);
    doPacking(b,this->numberOfExtendedAddressesPending_var);
    b->pack(addressList_arraysize);
    doPacking(b,this->addressList_var,addressList_arraysize);
    doPacking(b,this->sduLength_var);
    b->pack(sdu_arraysize);
    doPacking(b,this->sdu_var,sdu_arraysize);
}

void MlmeBeaconNotify_indication::parsimUnpack(cCommBuffer *b)
{
    MlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->bsn_var);
    doUnpacking(b,this->panDescriptor_var);
    doUnpacking(b,this->numberOfShortAddressesPending_var);
    doUnpacking(b,this->numberOfExtendedAddressesPending_var);
    delete [] this->addressList_var;
    b->unpack(addressList_arraysize);
    if (addressList_arraysize==0) {
        this->addressList_var = 0;
    } else {
        this->addressList_var = new unsigned long[addressList_arraysize];
        doUnpacking(b,this->addressList_var,addressList_arraysize);
    }
    doUnpacking(b,this->sduLength_var);
    delete [] this->sdu_var;
    b->unpack(sdu_arraysize);
    if (sdu_arraysize==0) {
        this->sdu_var = 0;
    } else {
        this->sdu_var = new unsigned int[sdu_arraysize];
        doUnpacking(b,this->sdu_var,sdu_arraysize);
    }
}

unsigned char MlmeBeaconNotify_indication::getBsn() const
{
    return bsn_var;
}

void MlmeBeaconNotify_indication::setBsn(unsigned char bsn_var)
{
    this->bsn_var = bsn_var;
}

PanDescriptor& MlmeBeaconNotify_indication::getPanDescriptor()
{
    return panDescriptor_var;
}

void MlmeBeaconNotify_indication::setPanDescriptor(const PanDescriptor& panDescriptor_var)
{
    this->panDescriptor_var = panDescriptor_var;
}

unsigned char MlmeBeaconNotify_indication::getNumberOfShortAddressesPending() const
{
    return numberOfShortAddressesPending_var;
}

void MlmeBeaconNotify_indication::setNumberOfShortAddressesPending(unsigned char numberOfShortAddressesPending_var)
{
    this->numberOfShortAddressesPending_var = numberOfShortAddressesPending_var;
}

unsigned char MlmeBeaconNotify_indication::getNumberOfExtendedAddressesPending() const
{
    return numberOfExtendedAddressesPending_var;
}

void MlmeBeaconNotify_indication::setNumberOfExtendedAddressesPending(unsigned char numberOfExtendedAddressesPending_var)
{
    this->numberOfExtendedAddressesPending_var = numberOfExtendedAddressesPending_var;
}

void MlmeBeaconNotify_indication::setAddressListArraySize(unsigned int size)
{
    unsigned long *addressList_var2 = (size==0) ? NULL : new unsigned long[size];
    unsigned int sz = addressList_arraysize < size ? addressList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        addressList_var2[i] = this->addressList_var[i];
    for (unsigned int i=sz; i<size; i++)
        addressList_var2[i] = 0;
    addressList_arraysize = size;
    delete [] this->addressList_var;
    this->addressList_var = addressList_var2;
}

unsigned int MlmeBeaconNotify_indication::getAddressListArraySize() const
{
    return addressList_arraysize;
}

unsigned long MlmeBeaconNotify_indication::getAddressList(unsigned int k) const
{
    if (k>=addressList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", addressList_arraysize, k);
    return addressList_var[k];
}

void MlmeBeaconNotify_indication::setAddressList(unsigned int k, unsigned long addressList_var)
{
    if (k>=addressList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", addressList_arraysize, k);
    this->addressList_var[k]=addressList_var;
}

unsigned int MlmeBeaconNotify_indication::getSduLength() const
{
    return sduLength_var;
}

void MlmeBeaconNotify_indication::setSduLength(unsigned int sduLength_var)
{
    this->sduLength_var = sduLength_var;
}

void MlmeBeaconNotify_indication::setSduArraySize(unsigned int size)
{
    unsigned int *sdu_var2 = (size==0) ? NULL : new unsigned int[size];
    unsigned int sz = sdu_arraysize < size ? sdu_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sdu_var2[i] = this->sdu_var[i];
    for (unsigned int i=sz; i<size; i++)
        sdu_var2[i] = 0;
    sdu_arraysize = size;
    delete [] this->sdu_var;
    this->sdu_var = sdu_var2;
}

unsigned int MlmeBeaconNotify_indication::getSduArraySize() const
{
    return sdu_arraysize;
}

unsigned int MlmeBeaconNotify_indication::getSdu(unsigned int k) const
{
    if (k>=sdu_arraysize) throw cRuntimeError("Array of size %d indexed by %d", sdu_arraysize, k);
    return sdu_var[k];
}

void MlmeBeaconNotify_indication::setSdu(unsigned int k, unsigned int sdu_var)
{
    if (k>=sdu_arraysize) throw cRuntimeError("Array of size %d indexed by %d", sdu_arraysize, k);
    this->sdu_var[k]=sdu_var;
}

class MlmeBeaconNotify_indicationDescriptor : public cClassDescriptor
{
  public:
    MlmeBeaconNotify_indicationDescriptor();
    virtual ~MlmeBeaconNotify_indicationDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MlmeBeaconNotify_indicationDescriptor);

MlmeBeaconNotify_indicationDescriptor::MlmeBeaconNotify_indicationDescriptor() : cClassDescriptor("MlmeBeaconNotify_indication", "MlmeMsg")
{
}

MlmeBeaconNotify_indicationDescriptor::~MlmeBeaconNotify_indicationDescriptor()
{
}

bool MlmeBeaconNotify_indicationDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MlmeBeaconNotify_indication *>(obj)!=NULL;
}

const char *MlmeBeaconNotify_indicationDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MlmeBeaconNotify_indicationDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int MlmeBeaconNotify_indicationDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISCOMPOUND;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISARRAY | FD_ISEDITABLE;
        case 5: return FD_ISEDITABLE;
        case 6: return FD_ISARRAY | FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MlmeBeaconNotify_indicationDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "bsn";
        case 1: return "panDescriptor";
        case 2: return "numberOfShortAddressesPending";
        case 3: return "numberOfExtendedAddressesPending";
        case 4: return "addressList";
        case 5: return "sduLength";
        case 6: return "sdu";
        default: return NULL;
    }
}

const char *MlmeBeaconNotify_indicationDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "PanDescriptor";
        case 2: return "unsigned char";
        case 3: return "unsigned char";
        case 4: return "unsigned long";
        case 5: return "unsigned int";
        case 6: return "unsigned int";
        default: return NULL;
    }
}

const char *MlmeBeaconNotify_indicationDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MlmeBeaconNotify_indicationDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MlmeBeaconNotify_indication *pp = (MlmeBeaconNotify_indication *)object; (void)pp;
    switch (field) {
        case 4: return pp->getAddressListArraySize();
        case 6: return pp->getSduArraySize();
        default: return 0;
    }
}

bool MlmeBeaconNotify_indicationDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MlmeBeaconNotify_indication *pp = (MlmeBeaconNotify_indication *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getBsn(),resultbuf,bufsize); return true;
        case 1: {std::stringstream out; out << pp->getPanDescriptor(); opp_strprettytrunc(resultbuf,out.str().c_str(),bufsize-1); return true;}
        case 2: ulong2string(pp->getNumberOfShortAddressesPending(),resultbuf,bufsize); return true;
        case 3: ulong2string(pp->getNumberOfExtendedAddressesPending(),resultbuf,bufsize); return true;
        case 4: ulong2string(pp->getAddressList(i),resultbuf,bufsize); return true;
        case 5: ulong2string(pp->getSduLength(),resultbuf,bufsize); return true;
        case 6: ulong2string(pp->getSdu(i),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MlmeBeaconNotify_indicationDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MlmeBeaconNotify_indication *pp = (MlmeBeaconNotify_indication *)object; (void)pp;
    switch (field) {
        case 0: pp->setBsn(string2ulong(value)); return true;
        case 2: pp->setNumberOfShortAddressesPending(string2ulong(value)); return true;
        case 3: pp->setNumberOfExtendedAddressesPending(string2ulong(value)); return true;
        case 4: pp->setAddressList(i,string2ulong(value)); return true;
        case 5: pp->setSduLength(string2ulong(value)); return true;
        case 6: pp->setSdu(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *MlmeBeaconNotify_indicationDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1: return "PanDescriptor"; break;
        default: return NULL;
    }
}

void *MlmeBeaconNotify_indicationDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MlmeBeaconNotify_indication *pp = (MlmeBeaconNotify_indication *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getPanDescriptor()); break;
        default: return NULL;
    }
}

Register_Class(McpsMsg);

McpsMsg::McpsMsg(const char *name, int kind) : cPacket(name,kind)
{
}

McpsMsg::McpsMsg(const McpsMsg& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

McpsMsg::~McpsMsg()
{
}

McpsMsg& McpsMsg::operator=(const McpsMsg& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void McpsMsg::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void McpsMsg::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class McpsMsgDescriptor : public cClassDescriptor
{
  public:
    McpsMsgDescriptor();
    virtual ~McpsMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(McpsMsgDescriptor);

McpsMsgDescriptor::McpsMsgDescriptor() : cClassDescriptor("McpsMsg", "cPacket")
{
}

McpsMsgDescriptor::~McpsMsgDescriptor()
{
}

bool McpsMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<McpsMsg *>(obj)!=NULL;
}

const char *McpsMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int McpsMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int McpsMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return 0;
    }
}

const char *McpsMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *McpsMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *McpsMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int McpsMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    McpsMsg *pp = (McpsMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool McpsMsgDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    McpsMsg *pp = (McpsMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

bool McpsMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    McpsMsg *pp = (McpsMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *McpsMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *McpsMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    McpsMsg *pp = (McpsMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MacBeacon);

MacBeacon::MacBeacon(const char *name, int kind) : McpsMsg(name,kind)
{
    this->beaconOrder_var = 0;
    this->superframeOrder_var = 0;
    this->finalCapSlot_var = 0;
    this->batteryLifeExtension_var = 0;
    this->panCoordinator_var = 0;
    this->associationPermit_var = 0;
    this->gtsDescriptorCount_var = 0;
    this->gtsPermit_var = 0;
    this->directionMask_var = 0;
    gtsList_arraysize = 0;
    this->gtsList_var = 0;
    this->numberOfShortAddressesPending_var = 0;
    this->numberOfExtendedAddressesPending_var = 0;
    addressList_arraysize = 0;
    this->addressList_var = 0;
    macBeaconPayload_arraysize = 0;
    this->macBeaconPayload_var = 0;
}

MacBeacon::MacBeacon(const MacBeacon& other) : McpsMsg()
{
    setName(other.getName());
    gtsList_arraysize = 0;
    this->gtsList_var = 0;
    addressList_arraysize = 0;
    this->addressList_var = 0;
    macBeaconPayload_arraysize = 0;
    this->macBeaconPayload_var = 0;
    operator=(other);
}

MacBeacon::~MacBeacon()
{
    delete [] gtsList_var;
    delete [] addressList_var;
    delete [] macBeaconPayload_var;
}

MacBeacon& MacBeacon::operator=(const MacBeacon& other)
{
    if (this==&other) return *this;
    McpsMsg::operator=(other);
    this->beaconOrder_var = other.beaconOrder_var;
    this->superframeOrder_var = other.superframeOrder_var;
    this->finalCapSlot_var = other.finalCapSlot_var;
    this->batteryLifeExtension_var = other.batteryLifeExtension_var;
    this->panCoordinator_var = other.panCoordinator_var;
    this->associationPermit_var = other.associationPermit_var;
    this->gtsDescriptorCount_var = other.gtsDescriptorCount_var;
    this->gtsPermit_var = other.gtsPermit_var;
    this->directionMask_var = other.directionMask_var;
    delete [] this->gtsList_var;
    this->gtsList_var = (other.gtsList_arraysize==0) ? NULL : new GtsDescriptor[other.gtsList_arraysize];
    gtsList_arraysize = other.gtsList_arraysize;
    for (unsigned int i=0; i<gtsList_arraysize; i++)
        this->gtsList_var[i] = other.gtsList_var[i];
    this->numberOfShortAddressesPending_var = other.numberOfShortAddressesPending_var;
    this->numberOfExtendedAddressesPending_var = other.numberOfExtendedAddressesPending_var;
    delete [] this->addressList_var;
    this->addressList_var = (other.addressList_arraysize==0) ? NULL : new unsigned long[other.addressList_arraysize];
    addressList_arraysize = other.addressList_arraysize;
    for (unsigned int i=0; i<addressList_arraysize; i++)
        this->addressList_var[i] = other.addressList_var[i];
    delete [] this->macBeaconPayload_var;
    this->macBeaconPayload_var = (other.macBeaconPayload_arraysize==0) ? NULL : new unsigned int[other.macBeaconPayload_arraysize];
    macBeaconPayload_arraysize = other.macBeaconPayload_arraysize;
    for (unsigned int i=0; i<macBeaconPayload_arraysize; i++)
        this->macBeaconPayload_var[i] = other.macBeaconPayload_var[i];
    return *this;
}

void MacBeacon::parsimPack(cCommBuffer *b)
{
    McpsMsg::parsimPack(b);
    doPacking(b,this->beaconOrder_var);
    doPacking(b,this->superframeOrder_var);
    doPacking(b,this->finalCapSlot_var);
    doPacking(b,this->batteryLifeExtension_var);
    doPacking(b,this->panCoordinator_var);
    doPacking(b,this->associationPermit_var);
    doPacking(b,this->gtsDescriptorCount_var);
    doPacking(b,this->gtsPermit_var);
    doPacking(b,this->directionMask_var);
    b->pack(gtsList_arraysize);
    doPacking(b,this->gtsList_var,gtsList_arraysize);
    doPacking(b,this->numberOfShortAddressesPending_var);
    doPacking(b,this->numberOfExtendedAddressesPending_var);
    b->pack(addressList_arraysize);
    doPacking(b,this->addressList_var,addressList_arraysize);
    b->pack(macBeaconPayload_arraysize);
    doPacking(b,this->macBeaconPayload_var,macBeaconPayload_arraysize);
}

void MacBeacon::parsimUnpack(cCommBuffer *b)
{
    McpsMsg::parsimUnpack(b);
    doUnpacking(b,this->beaconOrder_var);
    doUnpacking(b,this->superframeOrder_var);
    doUnpacking(b,this->finalCapSlot_var);
    doUnpacking(b,this->batteryLifeExtension_var);
    doUnpacking(b,this->panCoordinator_var);
    doUnpacking(b,this->associationPermit_var);
    doUnpacking(b,this->gtsDescriptorCount_var);
    doUnpacking(b,this->gtsPermit_var);
    doUnpacking(b,this->directionMask_var);
    delete [] this->gtsList_var;
    b->unpack(gtsList_arraysize);
    if (gtsList_arraysize==0) {
        this->gtsList_var = 0;
    } else {
        this->gtsList_var = new GtsDescriptor[gtsList_arraysize];
        doUnpacking(b,this->gtsList_var,gtsList_arraysize);
    }
    doUnpacking(b,this->numberOfShortAddressesPending_var);
    doUnpacking(b,this->numberOfExtendedAddressesPending_var);
    delete [] this->addressList_var;
    b->unpack(addressList_arraysize);
    if (addressList_arraysize==0) {
        this->addressList_var = 0;
    } else {
        this->addressList_var = new unsigned long[addressList_arraysize];
        doUnpacking(b,this->addressList_var,addressList_arraysize);
    }
    delete [] this->macBeaconPayload_var;
    b->unpack(macBeaconPayload_arraysize);
    if (macBeaconPayload_arraysize==0) {
        this->macBeaconPayload_var = 0;
    } else {
        this->macBeaconPayload_var = new unsigned int[macBeaconPayload_arraysize];
        doUnpacking(b,this->macBeaconPayload_var,macBeaconPayload_arraysize);
    }
}

unsigned char MacBeacon::getBeaconOrder() const
{
    return beaconOrder_var;
}

void MacBeacon::setBeaconOrder(unsigned char beaconOrder_var)
{
    this->beaconOrder_var = beaconOrder_var;
}

unsigned char MacBeacon::getSuperframeOrder() const
{
    return superframeOrder_var;
}

void MacBeacon::setSuperframeOrder(unsigned char superframeOrder_var)
{
    this->superframeOrder_var = superframeOrder_var;
}

unsigned char MacBeacon::getFinalCapSlot() const
{
    return finalCapSlot_var;
}

void MacBeacon::setFinalCapSlot(unsigned char finalCapSlot_var)
{
    this->finalCapSlot_var = finalCapSlot_var;
}

bool MacBeacon::getBatteryLifeExtension() const
{
    return batteryLifeExtension_var;
}

void MacBeacon::setBatteryLifeExtension(bool batteryLifeExtension_var)
{
    this->batteryLifeExtension_var = batteryLifeExtension_var;
}

bool MacBeacon::getPanCoordinator() const
{
    return panCoordinator_var;
}

void MacBeacon::setPanCoordinator(bool panCoordinator_var)
{
    this->panCoordinator_var = panCoordinator_var;
}

bool MacBeacon::getAssociationPermit() const
{
    return associationPermit_var;
}

void MacBeacon::setAssociationPermit(bool associationPermit_var)
{
    this->associationPermit_var = associationPermit_var;
}

unsigned char MacBeacon::getGtsDescriptorCount() const
{
    return gtsDescriptorCount_var;
}

void MacBeacon::setGtsDescriptorCount(unsigned char gtsDescriptorCount_var)
{
    this->gtsDescriptorCount_var = gtsDescriptorCount_var;
}

bool MacBeacon::getGtsPermit() const
{
    return gtsPermit_var;
}

void MacBeacon::setGtsPermit(bool gtsPermit_var)
{
    this->gtsPermit_var = gtsPermit_var;
}

unsigned char MacBeacon::getDirectionMask() const
{
    return directionMask_var;
}

void MacBeacon::setDirectionMask(unsigned char directionMask_var)
{
    this->directionMask_var = directionMask_var;
}

void MacBeacon::setGtsListArraySize(unsigned int size)
{
    GtsDescriptor *gtsList_var2 = (size==0) ? NULL : new GtsDescriptor[size];
    unsigned int sz = gtsList_arraysize < size ? gtsList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        gtsList_var2[i] = this->gtsList_var[i];
    gtsList_arraysize = size;
    delete [] this->gtsList_var;
    this->gtsList_var = gtsList_var2;
}

unsigned int MacBeacon::getGtsListArraySize() const
{
    return gtsList_arraysize;
}

GtsDescriptor& MacBeacon::getGtsList(unsigned int k)
{
    if (k>=gtsList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", gtsList_arraysize, k);
    return gtsList_var[k];
}

void MacBeacon::setGtsList(unsigned int k, const GtsDescriptor& gtsList_var)
{
    if (k>=gtsList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", gtsList_arraysize, k);
    this->gtsList_var[k]=gtsList_var;
}

unsigned char MacBeacon::getNumberOfShortAddressesPending() const
{
    return numberOfShortAddressesPending_var;
}

void MacBeacon::setNumberOfShortAddressesPending(unsigned char numberOfShortAddressesPending_var)
{
    this->numberOfShortAddressesPending_var = numberOfShortAddressesPending_var;
}

unsigned char MacBeacon::getNumberOfExtendedAddressesPending() const
{
    return numberOfExtendedAddressesPending_var;
}

void MacBeacon::setNumberOfExtendedAddressesPending(unsigned char numberOfExtendedAddressesPending_var)
{
    this->numberOfExtendedAddressesPending_var = numberOfExtendedAddressesPending_var;
}

void MacBeacon::setAddressListArraySize(unsigned int size)
{
    unsigned long *addressList_var2 = (size==0) ? NULL : new unsigned long[size];
    unsigned int sz = addressList_arraysize < size ? addressList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        addressList_var2[i] = this->addressList_var[i];
    for (unsigned int i=sz; i<size; i++)
        addressList_var2[i] = 0;
    addressList_arraysize = size;
    delete [] this->addressList_var;
    this->addressList_var = addressList_var2;
}

unsigned int MacBeacon::getAddressListArraySize() const
{
    return addressList_arraysize;
}

unsigned long MacBeacon::getAddressList(unsigned int k) const
{
    if (k>=addressList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", addressList_arraysize, k);
    return addressList_var[k];
}

void MacBeacon::setAddressList(unsigned int k, unsigned long addressList_var)
{
    if (k>=addressList_arraysize) throw cRuntimeError("Array of size %d indexed by %d", addressList_arraysize, k);
    this->addressList_var[k]=addressList_var;
}

void MacBeacon::setMacBeaconPayloadArraySize(unsigned int size)
{
    unsigned int *macBeaconPayload_var2 = (size==0) ? NULL : new unsigned int[size];
    unsigned int sz = macBeaconPayload_arraysize < size ? macBeaconPayload_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        macBeaconPayload_var2[i] = this->macBeaconPayload_var[i];
    for (unsigned int i=sz; i<size; i++)
        macBeaconPayload_var2[i] = 0;
    macBeaconPayload_arraysize = size;
    delete [] this->macBeaconPayload_var;
    this->macBeaconPayload_var = macBeaconPayload_var2;
}

unsigned int MacBeacon::getMacBeaconPayloadArraySize() const
{
    return macBeaconPayload_arraysize;
}

unsigned int MacBeacon::getMacBeaconPayload(unsigned int k) const
{
    if (k>=macBeaconPayload_arraysize) throw cRuntimeError("Array of size %d indexed by %d", macBeaconPayload_arraysize, k);
    return macBeaconPayload_var[k];
}

void MacBeacon::setMacBeaconPayload(unsigned int k, unsigned int macBeaconPayload_var)
{
    if (k>=macBeaconPayload_arraysize) throw cRuntimeError("Array of size %d indexed by %d", macBeaconPayload_arraysize, k);
    this->macBeaconPayload_var[k]=macBeaconPayload_var;
}

class MacBeaconDescriptor : public cClassDescriptor
{
  public:
    MacBeaconDescriptor();
    virtual ~MacBeaconDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MacBeaconDescriptor);

MacBeaconDescriptor::MacBeaconDescriptor() : cClassDescriptor("MacBeacon", "McpsMsg")
{
}

MacBeaconDescriptor::~MacBeaconDescriptor()
{
}

bool MacBeaconDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MacBeacon *>(obj)!=NULL;
}

const char *MacBeaconDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MacBeaconDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 14+basedesc->getFieldCount(object) : 14;
}

unsigned int MacBeaconDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISEDITABLE;
        case 5: return FD_ISEDITABLE;
        case 6: return FD_ISEDITABLE;
        case 7: return FD_ISEDITABLE;
        case 8: return FD_ISEDITABLE;
        case 9: return FD_ISARRAY | FD_ISCOMPOUND;
        case 10: return FD_ISEDITABLE;
        case 11: return FD_ISEDITABLE;
        case 12: return FD_ISARRAY | FD_ISEDITABLE;
        case 13: return FD_ISARRAY | FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MacBeaconDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "beaconOrder";
        case 1: return "superframeOrder";
        case 2: return "finalCapSlot";
        case 3: return "batteryLifeExtension";
        case 4: return "panCoordinator";
        case 5: return "associationPermit";
        case 6: return "gtsDescriptorCount";
        case 7: return "gtsPermit";
        case 8: return "directionMask";
        case 9: return "gtsList";
        case 10: return "numberOfShortAddressesPending";
        case 11: return "numberOfExtendedAddressesPending";
        case 12: return "addressList";
        case 13: return "macBeaconPayload";
        default: return NULL;
    }
}

const char *MacBeaconDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned char";
        case 2: return "unsigned char";
        case 3: return "bool";
        case 4: return "bool";
        case 5: return "bool";
        case 6: return "unsigned char";
        case 7: return "bool";
        case 8: return "unsigned char";
        case 9: return "GtsDescriptor";
        case 10: return "unsigned char";
        case 11: return "unsigned char";
        case 12: return "unsigned long";
        case 13: return "unsigned int";
        default: return NULL;
    }
}

const char *MacBeaconDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MacBeaconDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MacBeacon *pp = (MacBeacon *)object; (void)pp;
    switch (field) {
        case 9: return pp->getGtsListArraySize();
        case 12: return pp->getAddressListArraySize();
        case 13: return pp->getMacBeaconPayloadArraySize();
        default: return 0;
    }
}

bool MacBeaconDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MacBeacon *pp = (MacBeacon *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getBeaconOrder(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getSuperframeOrder(),resultbuf,bufsize); return true;
        case 2: ulong2string(pp->getFinalCapSlot(),resultbuf,bufsize); return true;
        case 3: bool2string(pp->getBatteryLifeExtension(),resultbuf,bufsize); return true;
        case 4: bool2string(pp->getPanCoordinator(),resultbuf,bufsize); return true;
        case 5: bool2string(pp->getAssociationPermit(),resultbuf,bufsize); return true;
        case 6: ulong2string(pp->getGtsDescriptorCount(),resultbuf,bufsize); return true;
        case 7: bool2string(pp->getGtsPermit(),resultbuf,bufsize); return true;
        case 8: ulong2string(pp->getDirectionMask(),resultbuf,bufsize); return true;
        case 9: {std::stringstream out; out << pp->getGtsList(i); opp_strprettytrunc(resultbuf,out.str().c_str(),bufsize-1); return true;}
        case 10: ulong2string(pp->getNumberOfShortAddressesPending(),resultbuf,bufsize); return true;
        case 11: ulong2string(pp->getNumberOfExtendedAddressesPending(),resultbuf,bufsize); return true;
        case 12: ulong2string(pp->getAddressList(i),resultbuf,bufsize); return true;
        case 13: ulong2string(pp->getMacBeaconPayload(i),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MacBeaconDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MacBeacon *pp = (MacBeacon *)object; (void)pp;
    switch (field) {
        case 0: pp->setBeaconOrder(string2ulong(value)); return true;
        case 1: pp->setSuperframeOrder(string2ulong(value)); return true;
        case 2: pp->setFinalCapSlot(string2ulong(value)); return true;
        case 3: pp->setBatteryLifeExtension(string2bool(value)); return true;
        case 4: pp->setPanCoordinator(string2bool(value)); return true;
        case 5: pp->setAssociationPermit(string2bool(value)); return true;
        case 6: pp->setGtsDescriptorCount(string2ulong(value)); return true;
        case 7: pp->setGtsPermit(string2bool(value)); return true;
        case 8: pp->setDirectionMask(string2ulong(value)); return true;
        case 10: pp->setNumberOfShortAddressesPending(string2ulong(value)); return true;
        case 11: pp->setNumberOfExtendedAddressesPending(string2ulong(value)); return true;
        case 12: pp->setAddressList(i,string2ulong(value)); return true;
        case 13: pp->setMacBeaconPayload(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *MacBeaconDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 9: return "GtsDescriptor"; break;
        default: return NULL;
    }
}

void *MacBeaconDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MacBeacon *pp = (MacBeacon *)object; (void)pp;
    switch (field) {
        case 9: return (void *)(&pp->getGtsList(i)); break;
        default: return NULL;
    }
}

Register_Class(MacCommand);

MacCommand::MacCommand(const char *name, int kind) : McpsMsg(name,kind)
{
    this->commandType_var = 0;
    commandPayload_arraysize = 0;
    this->commandPayload_var = 0;
}

MacCommand::MacCommand(const MacCommand& other) : McpsMsg()
{
    setName(other.getName());
    commandPayload_arraysize = 0;
    this->commandPayload_var = 0;
    operator=(other);
}

MacCommand::~MacCommand()
{
    delete [] commandPayload_var;
}

MacCommand& MacCommand::operator=(const MacCommand& other)
{
    if (this==&other) return *this;
    McpsMsg::operator=(other);
    this->commandType_var = other.commandType_var;
    delete [] this->commandPayload_var;
    this->commandPayload_var = (other.commandPayload_arraysize==0) ? NULL : new unsigned char[other.commandPayload_arraysize];
    commandPayload_arraysize = other.commandPayload_arraysize;
    for (unsigned int i=0; i<commandPayload_arraysize; i++)
        this->commandPayload_var[i] = other.commandPayload_var[i];
    return *this;
}

void MacCommand::parsimPack(cCommBuffer *b)
{
    McpsMsg::parsimPack(b);
    doPacking(b,this->commandType_var);
    b->pack(commandPayload_arraysize);
    doPacking(b,this->commandPayload_var,commandPayload_arraysize);
}

void MacCommand::parsimUnpack(cCommBuffer *b)
{
    McpsMsg::parsimUnpack(b);
    doUnpacking(b,this->commandType_var);
    delete [] this->commandPayload_var;
    b->unpack(commandPayload_arraysize);
    if (commandPayload_arraysize==0) {
        this->commandPayload_var = 0;
    } else {
        this->commandPayload_var = new unsigned char[commandPayload_arraysize];
        doUnpacking(b,this->commandPayload_var,commandPayload_arraysize);
    }
}

unsigned char MacCommand::getCommandType() const
{
    return commandType_var;
}

void MacCommand::setCommandType(unsigned char commandType_var)
{
    this->commandType_var = commandType_var;
}

void MacCommand::setCommandPayloadArraySize(unsigned int size)
{
    unsigned char *commandPayload_var2 = (size==0) ? NULL : new unsigned char[size];
    unsigned int sz = commandPayload_arraysize < size ? commandPayload_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        commandPayload_var2[i] = this->commandPayload_var[i];
    for (unsigned int i=sz; i<size; i++)
        commandPayload_var2[i] = 0;
    commandPayload_arraysize = size;
    delete [] this->commandPayload_var;
    this->commandPayload_var = commandPayload_var2;
}

unsigned int MacCommand::getCommandPayloadArraySize() const
{
    return commandPayload_arraysize;
}

unsigned char MacCommand::getCommandPayload(unsigned int k) const
{
    if (k>=commandPayload_arraysize) throw cRuntimeError("Array of size %d indexed by %d", commandPayload_arraysize, k);
    return commandPayload_var[k];
}

void MacCommand::setCommandPayload(unsigned int k, unsigned char commandPayload_var)
{
    if (k>=commandPayload_arraysize) throw cRuntimeError("Array of size %d indexed by %d", commandPayload_arraysize, k);
    this->commandPayload_var[k]=commandPayload_var;
}

class MacCommandDescriptor : public cClassDescriptor
{
  public:
    MacCommandDescriptor();
    virtual ~MacCommandDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MacCommandDescriptor);

MacCommandDescriptor::MacCommandDescriptor() : cClassDescriptor("MacCommand", "McpsMsg")
{
}

MacCommandDescriptor::~MacCommandDescriptor()
{
}

bool MacCommandDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MacCommand *>(obj)!=NULL;
}

const char *MacCommandDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MacCommandDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int MacCommandDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISARRAY | FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MacCommandDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "commandType";
        case 1: return "commandPayload";
        default: return NULL;
    }
}

const char *MacCommandDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned char";
        default: return NULL;
    }
}

const char *MacCommandDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MacCommandDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MacCommand *pp = (MacCommand *)object; (void)pp;
    switch (field) {
        case 1: return pp->getCommandPayloadArraySize();
        default: return 0;
    }
}

bool MacCommandDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MacCommand *pp = (MacCommand *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getCommandType(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getCommandPayload(i),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MacCommandDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MacCommand *pp = (MacCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setCommandType(string2ulong(value)); return true;
        case 1: pp->setCommandPayload(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *MacCommandDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MacCommandDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MacCommand *pp = (MacCommand *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MacAck);

MacAck::MacAck(const char *name, int kind) : McpsMsg(name,kind)
{
    this->sequenceNumber_var = 0;
}

MacAck::MacAck(const MacAck& other) : McpsMsg()
{
    setName(other.getName());
    operator=(other);
}

MacAck::~MacAck()
{
}

MacAck& MacAck::operator=(const MacAck& other)
{
    if (this==&other) return *this;
    McpsMsg::operator=(other);
    this->sequenceNumber_var = other.sequenceNumber_var;
    return *this;
}

void MacAck::parsimPack(cCommBuffer *b)
{
    McpsMsg::parsimPack(b);
    doPacking(b,this->sequenceNumber_var);
}

void MacAck::parsimUnpack(cCommBuffer *b)
{
    McpsMsg::parsimUnpack(b);
    doUnpacking(b,this->sequenceNumber_var);
}

unsigned char MacAck::getSequenceNumber() const
{
    return sequenceNumber_var;
}

void MacAck::setSequenceNumber(unsigned char sequenceNumber_var)
{
    this->sequenceNumber_var = sequenceNumber_var;
}

class MacAckDescriptor : public cClassDescriptor
{
  public:
    MacAckDescriptor();
    virtual ~MacAckDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(MacAckDescriptor);

MacAckDescriptor::MacAckDescriptor() : cClassDescriptor("MacAck", "McpsMsg")
{
}

MacAckDescriptor::~MacAckDescriptor()
{
}

bool MacAckDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MacAck *>(obj)!=NULL;
}

const char *MacAckDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MacAckDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int MacAckDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *MacAckDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "sequenceNumber";
        default: return NULL;
    }
}

const char *MacAckDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        default: return NULL;
    }
}

const char *MacAckDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int MacAckDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MacAck *pp = (MacAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool MacAckDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    MacAck *pp = (MacAck *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getSequenceNumber(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool MacAckDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MacAck *pp = (MacAck *)object; (void)pp;
    switch (field) {
        case 0: pp->setSequenceNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MacAckDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *MacAckDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MacAck *pp = (MacAck *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PlmeMsg);

PlmeMsg::PlmeMsg(const char *name, int kind) : cPacket(name,kind)
{
}

PlmeMsg::PlmeMsg(const PlmeMsg& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

PlmeMsg::~PlmeMsg()
{
}

PlmeMsg& PlmeMsg::operator=(const PlmeMsg& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void PlmeMsg::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void PlmeMsg::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class PlmeMsgDescriptor : public cClassDescriptor
{
  public:
    PlmeMsgDescriptor();
    virtual ~PlmeMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PlmeMsgDescriptor);

PlmeMsgDescriptor::PlmeMsgDescriptor() : cClassDescriptor("PlmeMsg", "cPacket")
{
}

PlmeMsgDescriptor::~PlmeMsgDescriptor()
{
}

bool PlmeMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlmeMsg *>(obj)!=NULL;
}

const char *PlmeMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlmeMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int PlmeMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return 0;
    }
}

const char *PlmeMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *PlmeMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *PlmeMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PlmeMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlmeMsg *pp = (PlmeMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PlmeMsgDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PlmeMsg *pp = (PlmeMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

bool PlmeMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlmeMsg *pp = (PlmeMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PlmeMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PlmeMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlmeMsg *pp = (PlmeMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PlmeSetTrxState_request);

PlmeSetTrxState_request::PlmeSetTrxState_request(const char *name, int kind) : PlmeMsg(name,kind)
{
    this->state_var = 0;
}

PlmeSetTrxState_request::PlmeSetTrxState_request(const PlmeSetTrxState_request& other) : PlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

PlmeSetTrxState_request::~PlmeSetTrxState_request()
{
}

PlmeSetTrxState_request& PlmeSetTrxState_request::operator=(const PlmeSetTrxState_request& other)
{
    if (this==&other) return *this;
    PlmeMsg::operator=(other);
    this->state_var = other.state_var;
    return *this;
}

void PlmeSetTrxState_request::parsimPack(cCommBuffer *b)
{
    PlmeMsg::parsimPack(b);
    doPacking(b,this->state_var);
}

void PlmeSetTrxState_request::parsimUnpack(cCommBuffer *b)
{
    PlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->state_var);
}

unsigned char PlmeSetTrxState_request::getState() const
{
    return state_var;
}

void PlmeSetTrxState_request::setState(unsigned char state_var)
{
    this->state_var = state_var;
}

class PlmeSetTrxState_requestDescriptor : public cClassDescriptor
{
  public:
    PlmeSetTrxState_requestDescriptor();
    virtual ~PlmeSetTrxState_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PlmeSetTrxState_requestDescriptor);

PlmeSetTrxState_requestDescriptor::PlmeSetTrxState_requestDescriptor() : cClassDescriptor("PlmeSetTrxState_request", "PlmeMsg")
{
}

PlmeSetTrxState_requestDescriptor::~PlmeSetTrxState_requestDescriptor()
{
}

bool PlmeSetTrxState_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlmeSetTrxState_request *>(obj)!=NULL;
}

const char *PlmeSetTrxState_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlmeSetTrxState_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int PlmeSetTrxState_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *PlmeSetTrxState_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "state";
        default: return NULL;
    }
}

const char *PlmeSetTrxState_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        default: return NULL;
    }
}

const char *PlmeSetTrxState_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PhyEnum";
            return NULL;
        default: return NULL;
    }
}

int PlmeSetTrxState_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSetTrxState_request *pp = (PlmeSetTrxState_request *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PlmeSetTrxState_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSetTrxState_request *pp = (PlmeSetTrxState_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getState(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool PlmeSetTrxState_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSetTrxState_request *pp = (PlmeSetTrxState_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setState(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PlmeSetTrxState_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PlmeSetTrxState_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSetTrxState_request *pp = (PlmeSetTrxState_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PlmeSetTrxState_confirm);

PlmeSetTrxState_confirm::PlmeSetTrxState_confirm(const char *name, int kind) : PlmeMsg(name,kind)
{
    this->status_var = 0;
}

PlmeSetTrxState_confirm::PlmeSetTrxState_confirm(const PlmeSetTrxState_confirm& other) : PlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

PlmeSetTrxState_confirm::~PlmeSetTrxState_confirm()
{
}

PlmeSetTrxState_confirm& PlmeSetTrxState_confirm::operator=(const PlmeSetTrxState_confirm& other)
{
    if (this==&other) return *this;
    PlmeMsg::operator=(other);
    this->status_var = other.status_var;
    return *this;
}

void PlmeSetTrxState_confirm::parsimPack(cCommBuffer *b)
{
    PlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
}

void PlmeSetTrxState_confirm::parsimUnpack(cCommBuffer *b)
{
    PlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
}

unsigned char PlmeSetTrxState_confirm::getStatus() const
{
    return status_var;
}

void PlmeSetTrxState_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

class PlmeSetTrxState_confirmDescriptor : public cClassDescriptor
{
  public:
    PlmeSetTrxState_confirmDescriptor();
    virtual ~PlmeSetTrxState_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PlmeSetTrxState_confirmDescriptor);

PlmeSetTrxState_confirmDescriptor::PlmeSetTrxState_confirmDescriptor() : cClassDescriptor("PlmeSetTrxState_confirm", "PlmeMsg")
{
}

PlmeSetTrxState_confirmDescriptor::~PlmeSetTrxState_confirmDescriptor()
{
}

bool PlmeSetTrxState_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlmeSetTrxState_confirm *>(obj)!=NULL;
}

const char *PlmeSetTrxState_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlmeSetTrxState_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int PlmeSetTrxState_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *PlmeSetTrxState_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        default: return NULL;
    }
}

const char *PlmeSetTrxState_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        default: return NULL;
    }
}

const char *PlmeSetTrxState_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PhyEnum";
            return NULL;
        default: return NULL;
    }
}

int PlmeSetTrxState_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSetTrxState_confirm *pp = (PlmeSetTrxState_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PlmeSetTrxState_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSetTrxState_confirm *pp = (PlmeSetTrxState_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool PlmeSetTrxState_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSetTrxState_confirm *pp = (PlmeSetTrxState_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PlmeSetTrxState_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PlmeSetTrxState_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSetTrxState_confirm *pp = (PlmeSetTrxState_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PlmeSet_request);

PlmeSet_request::PlmeSet_request(const char *name, int kind) : PlmeMsg(name,kind)
{
    this->PibAttribute_var = 0;
    PibAttributeValue_arraysize = 0;
    this->PibAttributeValue_var = 0;
}

PlmeSet_request::PlmeSet_request(const PlmeSet_request& other) : PlmeMsg()
{
    setName(other.getName());
    PibAttributeValue_arraysize = 0;
    this->PibAttributeValue_var = 0;
    operator=(other);
}

PlmeSet_request::~PlmeSet_request()
{
    delete [] PibAttributeValue_var;
}

PlmeSet_request& PlmeSet_request::operator=(const PlmeSet_request& other)
{
    if (this==&other) return *this;
    PlmeMsg::operator=(other);
    this->PibAttribute_var = other.PibAttribute_var;
    delete [] this->PibAttributeValue_var;
    this->PibAttributeValue_var = (other.PibAttributeValue_arraysize==0) ? NULL : new unsigned int[other.PibAttributeValue_arraysize];
    PibAttributeValue_arraysize = other.PibAttributeValue_arraysize;
    for (unsigned int i=0; i<PibAttributeValue_arraysize; i++)
        this->PibAttributeValue_var[i] = other.PibAttributeValue_var[i];
    return *this;
}

void PlmeSet_request::parsimPack(cCommBuffer *b)
{
    PlmeMsg::parsimPack(b);
    doPacking(b,this->PibAttribute_var);
    b->pack(PibAttributeValue_arraysize);
    doPacking(b,this->PibAttributeValue_var,PibAttributeValue_arraysize);
}

void PlmeSet_request::parsimUnpack(cCommBuffer *b)
{
    PlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->PibAttribute_var);
    delete [] this->PibAttributeValue_var;
    b->unpack(PibAttributeValue_arraysize);
    if (PibAttributeValue_arraysize==0) {
        this->PibAttributeValue_var = 0;
    } else {
        this->PibAttributeValue_var = new unsigned int[PibAttributeValue_arraysize];
        doUnpacking(b,this->PibAttributeValue_var,PibAttributeValue_arraysize);
    }
}

unsigned char PlmeSet_request::getPibAttribute() const
{
    return PibAttribute_var;
}

void PlmeSet_request::setPibAttribute(unsigned char PibAttribute_var)
{
    this->PibAttribute_var = PibAttribute_var;
}

void PlmeSet_request::setPibAttributeValueArraySize(unsigned int size)
{
    unsigned int *PibAttributeValue_var2 = (size==0) ? NULL : new unsigned int[size];
    unsigned int sz = PibAttributeValue_arraysize < size ? PibAttributeValue_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        PibAttributeValue_var2[i] = this->PibAttributeValue_var[i];
    for (unsigned int i=sz; i<size; i++)
        PibAttributeValue_var2[i] = 0;
    PibAttributeValue_arraysize = size;
    delete [] this->PibAttributeValue_var;
    this->PibAttributeValue_var = PibAttributeValue_var2;
}

unsigned int PlmeSet_request::getPibAttributeValueArraySize() const
{
    return PibAttributeValue_arraysize;
}

unsigned int PlmeSet_request::getPibAttributeValue(unsigned int k) const
{
    if (k>=PibAttributeValue_arraysize) throw cRuntimeError("Array of size %d indexed by %d", PibAttributeValue_arraysize, k);
    return PibAttributeValue_var[k];
}

void PlmeSet_request::setPibAttributeValue(unsigned int k, unsigned int PibAttributeValue_var)
{
    if (k>=PibAttributeValue_arraysize) throw cRuntimeError("Array of size %d indexed by %d", PibAttributeValue_arraysize, k);
    this->PibAttributeValue_var[k]=PibAttributeValue_var;
}

class PlmeSet_requestDescriptor : public cClassDescriptor
{
  public:
    PlmeSet_requestDescriptor();
    virtual ~PlmeSet_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PlmeSet_requestDescriptor);

PlmeSet_requestDescriptor::PlmeSet_requestDescriptor() : cClassDescriptor("PlmeSet_request", "PlmeMsg")
{
}

PlmeSet_requestDescriptor::~PlmeSet_requestDescriptor()
{
}

bool PlmeSet_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlmeSet_request *>(obj)!=NULL;
}

const char *PlmeSet_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlmeSet_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PlmeSet_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISARRAY | FD_ISEDITABLE;
        default: return 0;
    }
}

const char *PlmeSet_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "PibAttribute";
        case 1: return "PibAttributeValue";
        default: return NULL;
    }
}

const char *PlmeSet_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned int";
        default: return NULL;
    }
}

const char *PlmeSet_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PlmeSet_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSet_request *pp = (PlmeSet_request *)object; (void)pp;
    switch (field) {
        case 1: return pp->getPibAttributeValueArraySize();
        default: return 0;
    }
}

bool PlmeSet_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSet_request *pp = (PlmeSet_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getPibAttribute(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getPibAttributeValue(i),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool PlmeSet_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSet_request *pp = (PlmeSet_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setPibAttribute(string2ulong(value)); return true;
        case 1: pp->setPibAttributeValue(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *PlmeSet_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PlmeSet_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSet_request *pp = (PlmeSet_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PlmeSet_confirm);

PlmeSet_confirm::PlmeSet_confirm(const char *name, int kind) : PlmeMsg(name,kind)
{
    this->status_var = 0;
    this->PibAttribute_var = 0;
}

PlmeSet_confirm::PlmeSet_confirm(const PlmeSet_confirm& other) : PlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

PlmeSet_confirm::~PlmeSet_confirm()
{
}

PlmeSet_confirm& PlmeSet_confirm::operator=(const PlmeSet_confirm& other)
{
    if (this==&other) return *this;
    PlmeMsg::operator=(other);
    this->status_var = other.status_var;
    this->PibAttribute_var = other.PibAttribute_var;
    return *this;
}

void PlmeSet_confirm::parsimPack(cCommBuffer *b)
{
    PlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
    doPacking(b,this->PibAttribute_var);
}

void PlmeSet_confirm::parsimUnpack(cCommBuffer *b)
{
    PlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->PibAttribute_var);
}

unsigned char PlmeSet_confirm::getStatus() const
{
    return status_var;
}

void PlmeSet_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

unsigned char PlmeSet_confirm::getPibAttribute() const
{
    return PibAttribute_var;
}

void PlmeSet_confirm::setPibAttribute(unsigned char PibAttribute_var)
{
    this->PibAttribute_var = PibAttribute_var;
}

class PlmeSet_confirmDescriptor : public cClassDescriptor
{
  public:
    PlmeSet_confirmDescriptor();
    virtual ~PlmeSet_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PlmeSet_confirmDescriptor);

PlmeSet_confirmDescriptor::PlmeSet_confirmDescriptor() : cClassDescriptor("PlmeSet_confirm", "PlmeMsg")
{
}

PlmeSet_confirmDescriptor::~PlmeSet_confirmDescriptor()
{
}

bool PlmeSet_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlmeSet_confirm *>(obj)!=NULL;
}

const char *PlmeSet_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlmeSet_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PlmeSet_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *PlmeSet_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        case 1: return "PibAttribute";
        default: return NULL;
    }
}

const char *PlmeSet_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned char";
        default: return NULL;
    }
}

const char *PlmeSet_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PlmeSet_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSet_confirm *pp = (PlmeSet_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PlmeSet_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSet_confirm *pp = (PlmeSet_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getPibAttribute(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool PlmeSet_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSet_confirm *pp = (PlmeSet_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        case 1: pp->setPibAttribute(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PlmeSet_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PlmeSet_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlmeSet_confirm *pp = (PlmeSet_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PlmeEd_request);

PlmeEd_request::PlmeEd_request(const char *name, int kind) : PlmeMsg(name,kind)
{
}

PlmeEd_request::PlmeEd_request(const PlmeEd_request& other) : PlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

PlmeEd_request::~PlmeEd_request()
{
}

PlmeEd_request& PlmeEd_request::operator=(const PlmeEd_request& other)
{
    if (this==&other) return *this;
    PlmeMsg::operator=(other);
    return *this;
}

void PlmeEd_request::parsimPack(cCommBuffer *b)
{
    PlmeMsg::parsimPack(b);
}

void PlmeEd_request::parsimUnpack(cCommBuffer *b)
{
    PlmeMsg::parsimUnpack(b);
}

class PlmeEd_requestDescriptor : public cClassDescriptor
{
  public:
    PlmeEd_requestDescriptor();
    virtual ~PlmeEd_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PlmeEd_requestDescriptor);

PlmeEd_requestDescriptor::PlmeEd_requestDescriptor() : cClassDescriptor("PlmeEd_request", "PlmeMsg")
{
}

PlmeEd_requestDescriptor::~PlmeEd_requestDescriptor()
{
}

bool PlmeEd_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlmeEd_request *>(obj)!=NULL;
}

const char *PlmeEd_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlmeEd_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int PlmeEd_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return 0;
    }
}

const char *PlmeEd_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *PlmeEd_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *PlmeEd_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PlmeEd_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlmeEd_request *pp = (PlmeEd_request *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PlmeEd_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PlmeEd_request *pp = (PlmeEd_request *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

bool PlmeEd_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlmeEd_request *pp = (PlmeEd_request *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PlmeEd_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PlmeEd_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlmeEd_request *pp = (PlmeEd_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PlmeEd_confirm);

PlmeEd_confirm::PlmeEd_confirm(const char *name, int kind) : PlmeMsg(name,kind)
{
    this->status_var = 0;
    this->energyLevel_var = 0;
}

PlmeEd_confirm::PlmeEd_confirm(const PlmeEd_confirm& other) : PlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

PlmeEd_confirm::~PlmeEd_confirm()
{
}

PlmeEd_confirm& PlmeEd_confirm::operator=(const PlmeEd_confirm& other)
{
    if (this==&other) return *this;
    PlmeMsg::operator=(other);
    this->status_var = other.status_var;
    this->energyLevel_var = other.energyLevel_var;
    return *this;
}

void PlmeEd_confirm::parsimPack(cCommBuffer *b)
{
    PlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
    doPacking(b,this->energyLevel_var);
}

void PlmeEd_confirm::parsimUnpack(cCommBuffer *b)
{
    PlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->energyLevel_var);
}

unsigned char PlmeEd_confirm::getStatus() const
{
    return status_var;
}

void PlmeEd_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

unsigned char PlmeEd_confirm::getEnergyLevel() const
{
    return energyLevel_var;
}

void PlmeEd_confirm::setEnergyLevel(unsigned char energyLevel_var)
{
    this->energyLevel_var = energyLevel_var;
}

class PlmeEd_confirmDescriptor : public cClassDescriptor
{
  public:
    PlmeEd_confirmDescriptor();
    virtual ~PlmeEd_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PlmeEd_confirmDescriptor);

PlmeEd_confirmDescriptor::PlmeEd_confirmDescriptor() : cClassDescriptor("PlmeEd_confirm", "PlmeMsg")
{
}

PlmeEd_confirmDescriptor::~PlmeEd_confirmDescriptor()
{
}

bool PlmeEd_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlmeEd_confirm *>(obj)!=NULL;
}

const char *PlmeEd_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlmeEd_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PlmeEd_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *PlmeEd_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        case 1: return "energyLevel";
        default: return NULL;
    }
}

const char *PlmeEd_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned char";
        default: return NULL;
    }
}

const char *PlmeEd_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PlmeEd_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlmeEd_confirm *pp = (PlmeEd_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PlmeEd_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PlmeEd_confirm *pp = (PlmeEd_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getEnergyLevel(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool PlmeEd_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlmeEd_confirm *pp = (PlmeEd_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        case 1: pp->setEnergyLevel(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PlmeEd_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PlmeEd_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlmeEd_confirm *pp = (PlmeEd_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PlmeCca_request);

PlmeCca_request::PlmeCca_request(const char *name, int kind) : PlmeMsg(name,kind)
{
}

PlmeCca_request::PlmeCca_request(const PlmeCca_request& other) : PlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

PlmeCca_request::~PlmeCca_request()
{
}

PlmeCca_request& PlmeCca_request::operator=(const PlmeCca_request& other)
{
    if (this==&other) return *this;
    PlmeMsg::operator=(other);
    return *this;
}

void PlmeCca_request::parsimPack(cCommBuffer *b)
{
    PlmeMsg::parsimPack(b);
}

void PlmeCca_request::parsimUnpack(cCommBuffer *b)
{
    PlmeMsg::parsimUnpack(b);
}

class PlmeCca_requestDescriptor : public cClassDescriptor
{
  public:
    PlmeCca_requestDescriptor();
    virtual ~PlmeCca_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PlmeCca_requestDescriptor);

PlmeCca_requestDescriptor::PlmeCca_requestDescriptor() : cClassDescriptor("PlmeCca_request", "PlmeMsg")
{
}

PlmeCca_requestDescriptor::~PlmeCca_requestDescriptor()
{
}

bool PlmeCca_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlmeCca_request *>(obj)!=NULL;
}

const char *PlmeCca_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlmeCca_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int PlmeCca_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return 0;
    }
}

const char *PlmeCca_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *PlmeCca_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *PlmeCca_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PlmeCca_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlmeCca_request *pp = (PlmeCca_request *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PlmeCca_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PlmeCca_request *pp = (PlmeCca_request *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

bool PlmeCca_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlmeCca_request *pp = (PlmeCca_request *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PlmeCca_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PlmeCca_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlmeCca_request *pp = (PlmeCca_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PlmeCca_confirm);

PlmeCca_confirm::PlmeCca_confirm(const char *name, int kind) : PlmeMsg(name,kind)
{
    this->status_var = 0;
}

PlmeCca_confirm::PlmeCca_confirm(const PlmeCca_confirm& other) : PlmeMsg()
{
    setName(other.getName());
    operator=(other);
}

PlmeCca_confirm::~PlmeCca_confirm()
{
}

PlmeCca_confirm& PlmeCca_confirm::operator=(const PlmeCca_confirm& other)
{
    if (this==&other) return *this;
    PlmeMsg::operator=(other);
    this->status_var = other.status_var;
    return *this;
}

void PlmeCca_confirm::parsimPack(cCommBuffer *b)
{
    PlmeMsg::parsimPack(b);
    doPacking(b,this->status_var);
}

void PlmeCca_confirm::parsimUnpack(cCommBuffer *b)
{
    PlmeMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
}

unsigned char PlmeCca_confirm::getStatus() const
{
    return status_var;
}

void PlmeCca_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

class PlmeCca_confirmDescriptor : public cClassDescriptor
{
  public:
    PlmeCca_confirmDescriptor();
    virtual ~PlmeCca_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PlmeCca_confirmDescriptor);

PlmeCca_confirmDescriptor::PlmeCca_confirmDescriptor() : cClassDescriptor("PlmeCca_confirm", "PlmeMsg")
{
}

PlmeCca_confirmDescriptor::~PlmeCca_confirmDescriptor()
{
}

bool PlmeCca_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PlmeCca_confirm *>(obj)!=NULL;
}

const char *PlmeCca_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PlmeCca_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int PlmeCca_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *PlmeCca_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        default: return NULL;
    }
}

const char *PlmeCca_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        default: return NULL;
    }
}

const char *PlmeCca_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PhyEnum";
            return NULL;
        default: return NULL;
    }
}

int PlmeCca_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PlmeCca_confirm *pp = (PlmeCca_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PlmeCca_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PlmeCca_confirm *pp = (PlmeCca_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool PlmeCca_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PlmeCca_confirm *pp = (PlmeCca_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PlmeCca_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PlmeCca_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PlmeCca_confirm *pp = (PlmeCca_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PdMsg);

PdMsg::PdMsg(const char *name, int kind) : cPacket(name,kind)
{
    this->frameType_var = 0;
    this->securityEnabled_var = 0;
    this->framePending_var = 0;
    this->ackRequest_var = 0;
    this->panIdCompression_var = 0;
    this->destinationAddressingMode_var = 0;
    this->frameVersion_var = 0;
    this->sourceAddressingMode_var = 0;
    this->sequenceNumber_var = 0;
    this->destinationPanIdentifier_var = 0;
    this->destinationAddress_var = 0;
    this->sourcePanIdentifier_var = 0;
    this->sourceAddress_var = 0;
    auxiliarySecurityHeader_arraysize = 0;
    this->auxiliarySecurityHeader_var = 0;
    this->fcs_var = 0;
}

PdMsg::PdMsg(const PdMsg& other) : cPacket()
{
    setName(other.getName());
    auxiliarySecurityHeader_arraysize = 0;
    this->auxiliarySecurityHeader_var = 0;
    operator=(other);
}

PdMsg::~PdMsg()
{
    delete [] auxiliarySecurityHeader_var;
}

PdMsg& PdMsg::operator=(const PdMsg& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    this->frameType_var = other.frameType_var;
    this->securityEnabled_var = other.securityEnabled_var;
    this->framePending_var = other.framePending_var;
    this->ackRequest_var = other.ackRequest_var;
    this->panIdCompression_var = other.panIdCompression_var;
    this->destinationAddressingMode_var = other.destinationAddressingMode_var;
    this->frameVersion_var = other.frameVersion_var;
    this->sourceAddressingMode_var = other.sourceAddressingMode_var;
    this->sequenceNumber_var = other.sequenceNumber_var;
    this->destinationPanIdentifier_var = other.destinationPanIdentifier_var;
    this->destinationAddress_var = other.destinationAddress_var;
    this->sourcePanIdentifier_var = other.sourcePanIdentifier_var;
    this->sourceAddress_var = other.sourceAddress_var;
    delete [] this->auxiliarySecurityHeader_var;
    this->auxiliarySecurityHeader_var = (other.auxiliarySecurityHeader_arraysize==0) ? NULL : new unsigned char[other.auxiliarySecurityHeader_arraysize];
    auxiliarySecurityHeader_arraysize = other.auxiliarySecurityHeader_arraysize;
    for (unsigned int i=0; i<auxiliarySecurityHeader_arraysize; i++)
        this->auxiliarySecurityHeader_var[i] = other.auxiliarySecurityHeader_var[i];
    this->fcs_var = other.fcs_var;
    return *this;
}

void PdMsg::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->frameType_var);
    doPacking(b,this->securityEnabled_var);
    doPacking(b,this->framePending_var);
    doPacking(b,this->ackRequest_var);
    doPacking(b,this->panIdCompression_var);
    doPacking(b,this->destinationAddressingMode_var);
    doPacking(b,this->frameVersion_var);
    doPacking(b,this->sourceAddressingMode_var);
    doPacking(b,this->sequenceNumber_var);
    doPacking(b,this->destinationPanIdentifier_var);
    doPacking(b,this->destinationAddress_var);
    doPacking(b,this->sourcePanIdentifier_var);
    doPacking(b,this->sourceAddress_var);
    b->pack(auxiliarySecurityHeader_arraysize);
    doPacking(b,this->auxiliarySecurityHeader_var,auxiliarySecurityHeader_arraysize);
    doPacking(b,this->fcs_var);
}

void PdMsg::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->frameType_var);
    doUnpacking(b,this->securityEnabled_var);
    doUnpacking(b,this->framePending_var);
    doUnpacking(b,this->ackRequest_var);
    doUnpacking(b,this->panIdCompression_var);
    doUnpacking(b,this->destinationAddressingMode_var);
    doUnpacking(b,this->frameVersion_var);
    doUnpacking(b,this->sourceAddressingMode_var);
    doUnpacking(b,this->sequenceNumber_var);
    doUnpacking(b,this->destinationPanIdentifier_var);
    doUnpacking(b,this->destinationAddress_var);
    doUnpacking(b,this->sourcePanIdentifier_var);
    doUnpacking(b,this->sourceAddress_var);
    delete [] this->auxiliarySecurityHeader_var;
    b->unpack(auxiliarySecurityHeader_arraysize);
    if (auxiliarySecurityHeader_arraysize==0) {
        this->auxiliarySecurityHeader_var = 0;
    } else {
        this->auxiliarySecurityHeader_var = new unsigned char[auxiliarySecurityHeader_arraysize];
        doUnpacking(b,this->auxiliarySecurityHeader_var,auxiliarySecurityHeader_arraysize);
    }
    doUnpacking(b,this->fcs_var);
}

unsigned char PdMsg::getFrameType() const
{
    return frameType_var;
}

void PdMsg::setFrameType(unsigned char frameType_var)
{
    this->frameType_var = frameType_var;
}

bool PdMsg::getSecurityEnabled() const
{
    return securityEnabled_var;
}

void PdMsg::setSecurityEnabled(bool securityEnabled_var)
{
    this->securityEnabled_var = securityEnabled_var;
}

bool PdMsg::getFramePending() const
{
    return framePending_var;
}

void PdMsg::setFramePending(bool framePending_var)
{
    this->framePending_var = framePending_var;
}

bool PdMsg::getAckRequest() const
{
    return ackRequest_var;
}

void PdMsg::setAckRequest(bool ackRequest_var)
{
    this->ackRequest_var = ackRequest_var;
}

bool PdMsg::getPanIdCompression() const
{
    return panIdCompression_var;
}

void PdMsg::setPanIdCompression(bool panIdCompression_var)
{
    this->panIdCompression_var = panIdCompression_var;
}

unsigned char PdMsg::getDestinationAddressingMode() const
{
    return destinationAddressingMode_var;
}

void PdMsg::setDestinationAddressingMode(unsigned char destinationAddressingMode_var)
{
    this->destinationAddressingMode_var = destinationAddressingMode_var;
}

unsigned char PdMsg::getFrameVersion() const
{
    return frameVersion_var;
}

void PdMsg::setFrameVersion(unsigned char frameVersion_var)
{
    this->frameVersion_var = frameVersion_var;
}

unsigned char PdMsg::getSourceAddressingMode() const
{
    return sourceAddressingMode_var;
}

void PdMsg::setSourceAddressingMode(unsigned char sourceAddressingMode_var)
{
    this->sourceAddressingMode_var = sourceAddressingMode_var;
}

unsigned char PdMsg::getSequenceNumber() const
{
    return sequenceNumber_var;
}

void PdMsg::setSequenceNumber(unsigned char sequenceNumber_var)
{
    this->sequenceNumber_var = sequenceNumber_var;
}

unsigned short PdMsg::getDestinationPanIdentifier() const
{
    return destinationPanIdentifier_var;
}

void PdMsg::setDestinationPanIdentifier(unsigned short destinationPanIdentifier_var)
{
    this->destinationPanIdentifier_var = destinationPanIdentifier_var;
}

unsigned long PdMsg::getDestinationAddress() const
{
    return destinationAddress_var;
}

void PdMsg::setDestinationAddress(unsigned long destinationAddress_var)
{
    this->destinationAddress_var = destinationAddress_var;
}

unsigned short PdMsg::getSourcePanIdentifier() const
{
    return sourcePanIdentifier_var;
}

void PdMsg::setSourcePanIdentifier(unsigned short sourcePanIdentifier_var)
{
    this->sourcePanIdentifier_var = sourcePanIdentifier_var;
}

unsigned long PdMsg::getSourceAddress() const
{
    return sourceAddress_var;
}

void PdMsg::setSourceAddress(unsigned long sourceAddress_var)
{
    this->sourceAddress_var = sourceAddress_var;
}

void PdMsg::setAuxiliarySecurityHeaderArraySize(unsigned int size)
{
    unsigned char *auxiliarySecurityHeader_var2 = (size==0) ? NULL : new unsigned char[size];
    unsigned int sz = auxiliarySecurityHeader_arraysize < size ? auxiliarySecurityHeader_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        auxiliarySecurityHeader_var2[i] = this->auxiliarySecurityHeader_var[i];
    for (unsigned int i=sz; i<size; i++)
        auxiliarySecurityHeader_var2[i] = 0;
    auxiliarySecurityHeader_arraysize = size;
    delete [] this->auxiliarySecurityHeader_var;
    this->auxiliarySecurityHeader_var = auxiliarySecurityHeader_var2;
}

unsigned int PdMsg::getAuxiliarySecurityHeaderArraySize() const
{
    return auxiliarySecurityHeader_arraysize;
}

unsigned char PdMsg::getAuxiliarySecurityHeader(unsigned int k) const
{
    if (k>=auxiliarySecurityHeader_arraysize) throw cRuntimeError("Array of size %d indexed by %d", auxiliarySecurityHeader_arraysize, k);
    return auxiliarySecurityHeader_var[k];
}

void PdMsg::setAuxiliarySecurityHeader(unsigned int k, unsigned char auxiliarySecurityHeader_var)
{
    if (k>=auxiliarySecurityHeader_arraysize) throw cRuntimeError("Array of size %d indexed by %d", auxiliarySecurityHeader_arraysize, k);
    this->auxiliarySecurityHeader_var[k]=auxiliarySecurityHeader_var;
}

unsigned short PdMsg::getFcs() const
{
    return fcs_var;
}

void PdMsg::setFcs(unsigned short fcs_var)
{
    this->fcs_var = fcs_var;
}

class PdMsgDescriptor : public cClassDescriptor
{
  public:
    PdMsgDescriptor();
    virtual ~PdMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PdMsgDescriptor);

PdMsgDescriptor::PdMsgDescriptor() : cClassDescriptor("PdMsg", "cPacket")
{
}

PdMsgDescriptor::~PdMsgDescriptor()
{
}

bool PdMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PdMsg *>(obj)!=NULL;
}

const char *PdMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PdMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount(object) : 15;
}

unsigned int PdMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        case 2: return FD_ISEDITABLE;
        case 3: return FD_ISEDITABLE;
        case 4: return FD_ISEDITABLE;
        case 5: return FD_ISEDITABLE;
        case 6: return FD_ISEDITABLE;
        case 7: return FD_ISEDITABLE;
        case 8: return FD_ISEDITABLE;
        case 9: return FD_ISEDITABLE;
        case 10: return FD_ISEDITABLE;
        case 11: return FD_ISEDITABLE;
        case 12: return FD_ISEDITABLE;
        case 13: return FD_ISARRAY | FD_ISEDITABLE;
        case 14: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *PdMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "frameType";
        case 1: return "securityEnabled";
        case 2: return "framePending";
        case 3: return "ackRequest";
        case 4: return "panIdCompression";
        case 5: return "destinationAddressingMode";
        case 6: return "frameVersion";
        case 7: return "sourceAddressingMode";
        case 8: return "sequenceNumber";
        case 9: return "destinationPanIdentifier";
        case 10: return "destinationAddress";
        case 11: return "sourcePanIdentifier";
        case 12: return "sourceAddress";
        case 13: return "auxiliarySecurityHeader";
        case 14: return "fcs";
        default: return NULL;
    }
}

const char *PdMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "bool";
        case 2: return "bool";
        case 3: return "bool";
        case 4: return "bool";
        case 5: return "unsigned char";
        case 6: return "unsigned char";
        case 7: return "unsigned char";
        case 8: return "unsigned char";
        case 9: return "unsigned short";
        case 10: return "unsigned long";
        case 11: return "unsigned short";
        case 12: return "unsigned long";
        case 13: return "unsigned char";
        case 14: return "unsigned short";
        default: return NULL;
    }
}

const char *PdMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "FrameType";
            return NULL;
        default: return NULL;
    }
}

int PdMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PdMsg *pp = (PdMsg *)object; (void)pp;
    switch (field) {
        case 13: return pp->getAuxiliarySecurityHeaderArraySize();
        default: return 0;
    }
}

bool PdMsgDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PdMsg *pp = (PdMsg *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getFrameType(),resultbuf,bufsize); return true;
        case 1: bool2string(pp->getSecurityEnabled(),resultbuf,bufsize); return true;
        case 2: bool2string(pp->getFramePending(),resultbuf,bufsize); return true;
        case 3: bool2string(pp->getAckRequest(),resultbuf,bufsize); return true;
        case 4: bool2string(pp->getPanIdCompression(),resultbuf,bufsize); return true;
        case 5: ulong2string(pp->getDestinationAddressingMode(),resultbuf,bufsize); return true;
        case 6: ulong2string(pp->getFrameVersion(),resultbuf,bufsize); return true;
        case 7: ulong2string(pp->getSourceAddressingMode(),resultbuf,bufsize); return true;
        case 8: ulong2string(pp->getSequenceNumber(),resultbuf,bufsize); return true;
        case 9: ulong2string(pp->getDestinationPanIdentifier(),resultbuf,bufsize); return true;
        case 10: ulong2string(pp->getDestinationAddress(),resultbuf,bufsize); return true;
        case 11: ulong2string(pp->getSourcePanIdentifier(),resultbuf,bufsize); return true;
        case 12: ulong2string(pp->getSourceAddress(),resultbuf,bufsize); return true;
        case 13: ulong2string(pp->getAuxiliarySecurityHeader(i),resultbuf,bufsize); return true;
        case 14: ulong2string(pp->getFcs(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool PdMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PdMsg *pp = (PdMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setFrameType(string2ulong(value)); return true;
        case 1: pp->setSecurityEnabled(string2bool(value)); return true;
        case 2: pp->setFramePending(string2bool(value)); return true;
        case 3: pp->setAckRequest(string2bool(value)); return true;
        case 4: pp->setPanIdCompression(string2bool(value)); return true;
        case 5: pp->setDestinationAddressingMode(string2ulong(value)); return true;
        case 6: pp->setFrameVersion(string2ulong(value)); return true;
        case 7: pp->setSourceAddressingMode(string2ulong(value)); return true;
        case 8: pp->setSequenceNumber(string2ulong(value)); return true;
        case 9: pp->setDestinationPanIdentifier(string2ulong(value)); return true;
        case 10: pp->setDestinationAddress(string2ulong(value)); return true;
        case 11: pp->setSourcePanIdentifier(string2ulong(value)); return true;
        case 12: pp->setSourceAddress(string2ulong(value)); return true;
        case 13: pp->setAuxiliarySecurityHeader(i,string2ulong(value)); return true;
        case 14: pp->setFcs(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PdMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PdMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PdMsg *pp = (PdMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PdData_request);

PdData_request::PdData_request(const char *name, int kind) : PdMsg(name,kind)
{
    this->psduLength_var = 0;
}

PdData_request::PdData_request(const PdData_request& other) : PdMsg()
{
    setName(other.getName());
    operator=(other);
}

PdData_request::~PdData_request()
{
}

PdData_request& PdData_request::operator=(const PdData_request& other)
{
    if (this==&other) return *this;
    PdMsg::operator=(other);
    this->psduLength_var = other.psduLength_var;
    return *this;
}

void PdData_request::parsimPack(cCommBuffer *b)
{
    PdMsg::parsimPack(b);
    doPacking(b,this->psduLength_var);
}

void PdData_request::parsimUnpack(cCommBuffer *b)
{
    PdMsg::parsimUnpack(b);
    doUnpacking(b,this->psduLength_var);
}

unsigned int PdData_request::getPsduLength() const
{
    return psduLength_var;
}

void PdData_request::setPsduLength(unsigned int psduLength_var)
{
    this->psduLength_var = psduLength_var;
}

class PdData_requestDescriptor : public cClassDescriptor
{
  public:
    PdData_requestDescriptor();
    virtual ~PdData_requestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PdData_requestDescriptor);

PdData_requestDescriptor::PdData_requestDescriptor() : cClassDescriptor("PdData_request", "PdMsg")
{
}

PdData_requestDescriptor::~PdData_requestDescriptor()
{
}

bool PdData_requestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PdData_request *>(obj)!=NULL;
}

const char *PdData_requestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PdData_requestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int PdData_requestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *PdData_requestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "psduLength";
        default: return NULL;
    }
}

const char *PdData_requestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned int";
        default: return NULL;
    }
}

const char *PdData_requestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PdData_requestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PdData_request *pp = (PdData_request *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PdData_requestDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PdData_request *pp = (PdData_request *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getPsduLength(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool PdData_requestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PdData_request *pp = (PdData_request *)object; (void)pp;
    switch (field) {
        case 0: pp->setPsduLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PdData_requestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PdData_requestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PdData_request *pp = (PdData_request *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PdData_confirm);

PdData_confirm::PdData_confirm(const char *name, int kind) : PdMsg(name,kind)
{
    this->status_var = 0;
}

PdData_confirm::PdData_confirm(const PdData_confirm& other) : PdMsg()
{
    setName(other.getName());
    operator=(other);
}

PdData_confirm::~PdData_confirm()
{
}

PdData_confirm& PdData_confirm::operator=(const PdData_confirm& other)
{
    if (this==&other) return *this;
    PdMsg::operator=(other);
    this->status_var = other.status_var;
    return *this;
}

void PdData_confirm::parsimPack(cCommBuffer *b)
{
    PdMsg::parsimPack(b);
    doPacking(b,this->status_var);
}

void PdData_confirm::parsimUnpack(cCommBuffer *b)
{
    PdMsg::parsimUnpack(b);
    doUnpacking(b,this->status_var);
}

unsigned char PdData_confirm::getStatus() const
{
    return status_var;
}

void PdData_confirm::setStatus(unsigned char status_var)
{
    this->status_var = status_var;
}

class PdData_confirmDescriptor : public cClassDescriptor
{
  public:
    PdData_confirmDescriptor();
    virtual ~PdData_confirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PdData_confirmDescriptor);

PdData_confirmDescriptor::PdData_confirmDescriptor() : cClassDescriptor("PdData_confirm", "PdMsg")
{
}

PdData_confirmDescriptor::~PdData_confirmDescriptor()
{
}

bool PdData_confirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PdData_confirm *>(obj)!=NULL;
}

const char *PdData_confirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PdData_confirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int PdData_confirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *PdData_confirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "status";
        default: return NULL;
    }
}

const char *PdData_confirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        default: return NULL;
    }
}

const char *PdData_confirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PhyEnum";
            return NULL;
        default: return NULL;
    }
}

int PdData_confirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PdData_confirm *pp = (PdData_confirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PdData_confirmDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PdData_confirm *pp = (PdData_confirm *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getStatus(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool PdData_confirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PdData_confirm *pp = (PdData_confirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PdData_confirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PdData_confirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PdData_confirm *pp = (PdData_confirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PdData_indication);

PdData_indication::PdData_indication(const char *name, int kind) : PdMsg(name,kind)
{
    this->psduLength_var = 0;
    this->ppduLinkQuality_var = 0;
}

PdData_indication::PdData_indication(const PdData_indication& other) : PdMsg()
{
    setName(other.getName());
    operator=(other);
}

PdData_indication::~PdData_indication()
{
}

PdData_indication& PdData_indication::operator=(const PdData_indication& other)
{
    if (this==&other) return *this;
    PdMsg::operator=(other);
    this->psduLength_var = other.psduLength_var;
    this->ppduLinkQuality_var = other.ppduLinkQuality_var;
    return *this;
}

void PdData_indication::parsimPack(cCommBuffer *b)
{
    PdMsg::parsimPack(b);
    doPacking(b,this->psduLength_var);
    doPacking(b,this->ppduLinkQuality_var);
}

void PdData_indication::parsimUnpack(cCommBuffer *b)
{
    PdMsg::parsimUnpack(b);
    doUnpacking(b,this->psduLength_var);
    doUnpacking(b,this->ppduLinkQuality_var);
}

unsigned char PdData_indication::getPsduLength() const
{
    return psduLength_var;
}

void PdData_indication::setPsduLength(unsigned char psduLength_var)
{
    this->psduLength_var = psduLength_var;
}

unsigned char PdData_indication::getPpduLinkQuality() const
{
    return ppduLinkQuality_var;
}

void PdData_indication::setPpduLinkQuality(unsigned char ppduLinkQuality_var)
{
    this->ppduLinkQuality_var = ppduLinkQuality_var;
}

class PdData_indicationDescriptor : public cClassDescriptor
{
  public:
    PdData_indicationDescriptor();
    virtual ~PdData_indicationDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PdData_indicationDescriptor);

PdData_indicationDescriptor::PdData_indicationDescriptor() : cClassDescriptor("PdData_indication", "PdMsg")
{
}

PdData_indicationDescriptor::~PdData_indicationDescriptor()
{
}

bool PdData_indicationDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PdData_indication *>(obj)!=NULL;
}

const char *PdData_indicationDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PdData_indicationDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PdData_indicationDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return FD_ISEDITABLE;
        case 1: return FD_ISEDITABLE;
        default: return 0;
    }
}

const char *PdData_indicationDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "psduLength";
        case 1: return "ppduLinkQuality";
        default: return NULL;
    }
}

const char *PdData_indicationDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return "unsigned char";
        case 1: return "unsigned char";
        default: return NULL;
    }
}

const char *PdData_indicationDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PdData_indicationDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PdData_indication *pp = (PdData_indication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool PdData_indicationDescriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    PdData_indication *pp = (PdData_indication *)object; (void)pp;
    switch (field) {
        case 0: ulong2string(pp->getPsduLength(),resultbuf,bufsize); return true;
        case 1: ulong2string(pp->getPpduLinkQuality(),resultbuf,bufsize); return true;
        default: return false;
    }
}

bool PdData_indicationDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PdData_indication *pp = (PdData_indication *)object; (void)pp;
    switch (field) {
        case 0: pp->setPsduLength(string2ulong(value)); return true;
        case 1: pp->setPpduLinkQuality(string2ulong(value)); return true;
        default: return false;
    }
}

const char *PdData_indicationDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *PdData_indicationDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PdData_indication *pp = (PdData_indication *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(Frame802154);

Frame802154::Frame802154(const char *name, int kind) : cPacket(name,kind)
{
}

Frame802154::Frame802154(const Frame802154& other) : cPacket()
{
    setName(other.getName());
    operator=(other);
}

Frame802154::~Frame802154()
{
}

Frame802154& Frame802154::operator=(const Frame802154& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    return *this;
}

void Frame802154::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
}

void Frame802154::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
}

class Frame802154Descriptor : public cClassDescriptor
{
  public:
    Frame802154Descriptor();
    virtual ~Frame802154Descriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual bool getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(Frame802154Descriptor);

Frame802154Descriptor::Frame802154Descriptor() : cClassDescriptor("Frame802154", "cPacket")
{
}

Frame802154Descriptor::~Frame802154Descriptor()
{
}

bool Frame802154Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Frame802154 *>(obj)!=NULL;
}

const char *Frame802154Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int Frame802154Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int Frame802154Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return 0;
    }
}

const char *Frame802154Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *Frame802154Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

const char *Frame802154Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int Frame802154Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Frame802154 *pp = (Frame802154 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

bool Frame802154Descriptor::getFieldAsString(void *object, int field, int i, char *resultbuf, int bufsize) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i,resultbuf,bufsize);
        field -= basedesc->getFieldCount(object);
    }
    Frame802154 *pp = (Frame802154 *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

bool Frame802154Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Frame802154 *pp = (Frame802154 *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Frame802154Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

void *Frame802154Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Frame802154 *pp = (Frame802154 *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


