#ifndef DEVICES_GRAMMAR_HPP
#define DEVICES_GRAMMAR_HPP

#include <unordered_set>
#include <unordered_map>
#include "./GrammarComponents.hpp"


namespace formal_device
{
namespace grammar
{

class Regular
{
  public:
    template <class T>
    using set_type                     = std::unordered_set<T, Hasher>;
    template <class Key, class Value>
    using map_type                     = std::unordered_map<Key, Value, Hasher>;

    using symbol_type                  = Symbol;
    using terminal_production_type     = TerminalProduction;
    using non_terminal_production_type = NonTerminalProduction;
    using production_type_ptr          = ProductionPointer;

    using vocabulary_set_type          = set_type<symbol_type>;
    using production_map_type          = map_type<symbol_type, set_type<production_type_ptr>>;
    using pair_production_type         = std::pair<symbol_type, set_type<production_type_ptr>>;

    // Class constructors
    Regular() = default;

    Regular(const Regular &) = default;
    Regular &operator=(const Regular &) = default;

    Regular(Regular &&) = default;
    Regular &operator=(Regular &&) = default;

    template <class Arg1, class Arg2, class Arg3, class Arg4>
    Regular(Arg1 &&vn, Arg2 &&vt, Arg3 &&productions, Arg4 &&initial_symbol) :
        m_vn{std::forward<Arg1>(vn)},
        m_vt{std::forward<Arg2>(vt)},
        m_productions{std::forward<Arg3>(productions)},
        m_initial_symbol{std::forward<Arg4>(initial_symbol)}
    {
    }

  private:
    vocabulary_set_type m_vn;
    vocabulary_set_type m_vt;
    production_map_type m_productions;
    symbol_type         m_initial_symbol{"Error"};
};

}   // namespace grammar
}   // namespace formal_device

#endif // DEVICES_GRAMMAR_HPP
