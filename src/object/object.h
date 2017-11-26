#ifndef OBJECT_H
#define OBJECT_H

#include "util/constant.h"
#include "collision.h"
#include "light/light.h"

class Object //各种物体的基类
{
public:
    virtual ~Object()
    {

    }

    uint64 getI(void) const { return id; }
    //const Material* getM() const { return material; }
/*
    virtual std::string getType() const = 0;

    // 与视线相交
    virtual Collision collide(const Ray& ray) const = 0;

    // 交点处的纹理颜色
    virtual Color getTextureColor(const Collision& coll) const = 0;

    // 保存为 JSON 格式
    virtual Json::Value toJson() const;

    // 保存 JSON 到文件
    virtual void save(const std::string& file) const;

    // 从 JSON 导入物体
    static Object* loadFromJson(const Json::Value& value);

    // 从文件导入物体
    static Object* loadFrom(const std::string& file);
*/
protected:
    //Object(const Material* m);
    //Object(const Json::Value& object);

    //const Material* material;  // 材料属性
    uint64 id;         // 标识符

private:
};

#endif
