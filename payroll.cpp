#include <emscripten/emscripten.h>
#include <string>

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    const char* processInput(int startMonth, int startDay, int endMonth, int endDay, double totalHours, double hourlyRate, double bonus) {
        // Calculate pay (simple example, adjust as needed)
        double pay = (totalHours * hourlyRate) + bonus;

        // Create a result string
        std::string result = "Total pay from " + std::to_string(startMonth) + "/" + std::to_string(startDay) + 
                             " to " + std::to_string(endMonth) + "/" + std::to_string(endDay) + 
                             " is $" + std::to_string(pay);

        // Return the result as a C string (static to ensure it remains valid)
        static std::string resultStr = result;
        return resultStr.c_str();
    }
}
