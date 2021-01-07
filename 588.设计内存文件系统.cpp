class FileSystem {
  private:
    vector<string> split_path(string path)
    {
        if (path != "/") path += '/';
        int            pos = 1, n = path.size();
        vector<string> res;
        for (int i = 1; i < n; ++i)
            if (path[i] == '/') {
                res.push_back(path.substr(pos, i - pos));
                pos = i + 1;
            }
        return res;
    }

  public:
    struct File
    {
        map<string, File*> childs;
        bool               dir;
        string             content;
        File(bool dir = false) : dir(dir) {}
    };
    File* root;
    FileSystem()
    {
        root = new File(true);
    }

    vector<string> ls(string path)
    {
        vector<string> res;
        auto           paths = split_path(path);
        int            n     = paths.size();
        auto           p     = root;
        for (int i = 0; i < n; ++i) { p = p->childs[paths[i]]; }
        if (p->dir) {
            for (auto& i : p->childs) { res.push_back(i.first); }
        }
        else {
            res.push_back(paths[n - 1]);
        }
        return res;
    }

    void mkdir(string path)
    {
        vector<string> res;
        auto           paths = split_path(path);
        int            n     = paths.size();
        auto           p     = root;
        for (int i = 0; i < n; ++i) {
            if (p->childs[paths[i]] == nullptr)
                p = p->childs[paths[i]] = new File();
            else
                p = p->childs[paths[i]];
            p->dir = true;
        }
    }

    void addContentToFile(string filePath, string content)
    {
        vector<string> res;
        auto           paths = split_path(filePath);
        int            n     = paths.size();
        auto           p     = root;
        for (int i = 0; i < n - 1; ++i) { p = p->childs[paths[i]]; }
        auto f = p->childs[paths[n - 1]];
        if (f == nullptr) f = p->childs[paths[n - 1]] = new File(false);
        f->content += content;
    }

    string readContentFromFile(string filePath)
    {
        vector<string> res;
        auto           paths = split_path(filePath);
        int            n     = paths.size();
        auto           p     = root;
        for (int i = 0; i < n - 1; ++i) { p = p->childs[paths[i]]; }
        auto f = p->childs[paths[n - 1]];
        return f->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */