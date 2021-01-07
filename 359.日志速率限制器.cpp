class Logger {
  public:
    deque<pair<int, string>> log;
    int                      ts;
    /** Initialize your data structure here. */
    Logger() : ts(0) {}
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message)
    {
        while (log.size() && log.front().first <= timestamp - 10) log.pop_front();
        for (auto& p : log)
            if (p.second == message) return false;
        log.push_back(make_pair(timestamp, message));
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */