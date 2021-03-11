#ifndef LEPTJSON_H__
#define LEPTJSON_H__
//多个文件或目录结构，可以用 项目名称_目录_文件名称_H_ 这种命名方式

//json的六种数据类型
typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

//c没有命名空间，所以一般项目简写作为标识符的前缀
//每个结点使用lept_value结构体表示
//用结构体来代替命名空间
typedef struct {
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR
};

//传入字符串和树根节点
int lept_parse(lept_value* v, const char* json);

//获取类型的结果函数
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
