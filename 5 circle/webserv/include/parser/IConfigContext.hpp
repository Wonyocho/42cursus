#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
#include "IConfigDirective.hpp"

class IConfigDirective;

enum ContextType
{
	MAIN,
	HTTP,
	SERVER,
	EVENTS,
	LOCATION,
};

class IConfigContext
{
	private:
		IConfigContext *parent_;
		int contextType_;
		std::vector<std::string> options_;
		std::vector<IConfigContext *> child_;
		std::vector<IConfigDirective *> directives_;

		void AddChild(IConfigContext *child);

	public:
		IConfigContext(IConfigContext *parent, int contextType);
		~IConfigContext();

		// Getters
		IConfigContext* getParent() const;
		int getType() const;
		std::vector<std::string> getOptions() const;
		std::vector<IConfigContext *> getChild() const;
		std::vector<IConfigDirective *> getDirectives() const;

		void AddDirectives(IConfigDirective *directive);
		void AddOptions(std::string token);
		void PrintType(std::ostream &os) const;
		bool IsValid() const;
};

int IsContext(std::string token);
void DeleteTree(IConfigContext *root);