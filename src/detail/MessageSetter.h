#ifndef DETAIL_MESSAGESETTER_H
#define DETAIL_MESSAGESETTER_H

#include <string>

namespace googlex {
namespace protobuf {
class Descriptor;
class FieldDescriptor;
class Message;
class Reflection;
}  // namespace protobuf
}  // namespace google

namespace LuaIntf {
class LuaRef;
}  // namespace LuaIntf

// To set the message or message field.
class MessageSetter final
{
public:
    explicit MessageSetter(googlex::protobuf::Message& rMsg);

public:
    using LuaRef = LuaIntf::LuaRef;
    using string = std::string;

    void SetField(const string& sField, const LuaRef& luaValue);
    void SetMsg(const LuaRef& luaTable);

private:
    using FieldDescriptor = googlex::protobuf::FieldDescriptor;
    void SetRepeatedField(const FieldDescriptor& field,
        const LuaRef& luaTable);
    void SetRepeatedMapField(const FieldDescriptor& field,
        const LuaRef& luaTable);
    void AddToRepeatedField(const FieldDescriptor& field,
        const LuaRef& luaValue);
    void AddToMapField(const FieldDescriptor& field,
        const LuaRef& key, const LuaRef& val);
    int GetEnumValue(const LuaRef& luaValue,
        const FieldDescriptor& field) const;

private:
    googlex::protobuf::Message& m_rMsg;
    const googlex::protobuf::Descriptor* m_pDesc;  // = m_rMsg.GetDescriptor();
    const googlex::protobuf::Reflection* m_pRefl;  // = m_rMsg.GetReflection();
};  // class MessageSetter

#endif  // DETAIL_MESSAGESETTER_H
