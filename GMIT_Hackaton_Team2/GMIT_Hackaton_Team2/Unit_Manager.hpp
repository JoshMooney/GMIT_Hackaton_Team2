#ifndef UNIT_MANAGER_HPP
#define UNIT_MANAGER_HPP

#include <string>
#include <vector>
#include "Base_Unit.hpp"
#include "Light_Unit.hpp"
#include "Med_Unit.hpp"
#include "Heavy_Unit.hpp"

class Unit_Manager{
private:
	std::vector<Base_Unit*> m_container;
public:
	Unit_Manager(){}
	~Unit_Manager(){}
	
	void addUnit(std::string type, bool dir, b2World *m_world, Renderer &renderer){
		b2Vec2 start_position;
		if(dir)
			start_position = b2Vec2(120, 390);
		else
			start_position = b2Vec2(830, 390);
			
		
		if(type == "Heavy")
			m_container.push_back(new Heavy_Unit(start_position, 40, 40, dir, m_world, renderer));
		else if(type == "Med")
			m_container.push_back(new Med_Unit(start_position, 40, 40, dir, m_world, renderer));
		else if (type == "Light")
			m_container.push_back(new Light_Unit(start_position, 40, 40, dir, m_world, renderer));
	}
	void clear(){
		//m_container.clear();
	}
	void cullUnits(b2World *world){
		for (int i = 0; i < m_container.size(); i++){
			if(!m_container[i]->m_active){
				world->DestroyBody(m_container[i]->m_box_body);
				m_container.erase(std::remove(m_container.begin(), m_container.end(), m_container[i]), m_container.end());
			}
		}
	}
	void update(){
		for (int i = 0; i < m_container.size(); i++)
			m_container[i]->update();
	}
	void render(Renderer &r){
		for (int i = 0; i < m_container.size(); i++)
			if(m_container[i]->m_active)
				m_container[i]->render(r);
	}
};

#endif