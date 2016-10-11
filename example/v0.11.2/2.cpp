 #include <v8.h> 

 using namespace v8; 



//读取js文件,返回js文件源码
v8::Handle<v8::String> ReadFile(const char* name)
{
    FILE* file = fopen(name, "rb");
    if (file == NULL) return v8::Handle<v8::String>();
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    char* chars = new char[size + 1];
    chars[size] = '\0';
    for (int i = 0; i < size;)
    {
     int read = fread(&chars[i], 1, size - i, file);
     i += read;
    }
    fclose(file);
    v8::Handle<v8::String> result = v8::String::New(chars, size);
    delete[] chars;
    return result;
}

//执行js源代码,其中有编译和运行两个小步骤,并直接打印结果
void ExecuteString(const v8::Handle<v8::String> &source)
{
    v8::HandleScope handle_scope;
    v8::Handle<v8::Script> script = v8::Script::Compile(source);

    v8::Handle<v8::Value> result = script->Run();
    v8::String::Utf8Value str(result);
    printf("%s\r\n", *str);
}



int main(int argc, char *argv[]) { 

    v8::HandleScope handle_scope;
    Persistent<Context> context = Context::New(); 
    Context::Scope context_scope(context);

	ExecuteString(ReadFile("test.js"));

    context.Dispose();

	return 0; 
 }
