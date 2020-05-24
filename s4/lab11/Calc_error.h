#pragma once
#include <stdexcept>

/*
 * Error class that stores previously thrown runtime_error in pointer. 
 * Because it extends runtime_error, it can be used chained for unraveling 
 * sequences of catch-throw by passing its own type in constructor of subsequent throws.
 *
 * what() method displays file and line it was thrown from in addition to standard message.
 */
class Calc_error: public std::runtime_error
{
public:
    /*
     * Constructor
     * @param exc last caught exception (runtime_error* or Calc_error*)
     * @param msg message to be displayed on what() call
     * @param path pass __FILE__ for current file
     * @param line __LINE__ for current line
     */
    Calc_error(std::runtime_error* exc, const std::string& msg, const std::string& path, int line):
            std::runtime_error(msg + ", [plik = " + path + ", linia = " + std::to_string(line) + "]"),
            m_exc{exc}
    {}
    
    /*
     * Handles Calc_error and manages memory.
     * Will unravel all previous errors stored in m_exc and clear memory.
     */
    static void handler()
    {
        try
        {
            throw;
        }
        catch (std::runtime_error* exc)
        {
            std::cout << " Zlapano wyjatek:" << std::endl;
            while (exc)
            {
                std::cout << " -- z powodu: ";
                std::cout << exc->what() << std::endl;
                
                auto q = dynamic_cast<Calc_error*>(exc);
                if (q)
                {
                    exc = q->m_exc;
                    delete q;
                }
                else
                {
                    delete exc;
                    exc = nullptr;
                }
            }
        }
    }

private:
    std::runtime_error* m_exc = nullptr;
    
};