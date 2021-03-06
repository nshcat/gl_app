#pragma once


namespace utility::pnfa::internal
{
	template<	typename Tinput,
				typename... Tstate
	>
	sub_automaton<Tinput, Tstate...>::sub_automaton(node_id p_id, automaton_type&& p_child)
		: node_base(node_type::sub_automaton, p_id),
			m_Child{ ::std::make_unique<automaton_type>(::std::move(p_child)) }
	{
	}
	
	
	template<	typename Tinput,
				typename... Tstate
	>
	auto sub_automaton<Tinput, Tstate...>::view()
		-> automaton_view
	{
		return { dynamic_cast<automaton_type*>(m_Child.get()) };
	}
	
	
	template<	typename Tinput,
				typename... Tstate
	>
	auto sub_automaton<Tinput, Tstate...>::clone() const
		-> ::std::unique_ptr<node_base>
	{
		const auto t_ptr = dynamic_cast<automaton_type*>(m_Child.get());
		return ::std::make_unique<this_type>(this->id(), automaton_type{*t_ptr});
	}
}

