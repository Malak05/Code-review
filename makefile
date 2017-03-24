all: ta

CPPSOURCES=${wildcard *.cpp}

CSOURCES=${wildcard *.c}

SOURCE_DEPENDENCIES=$(CPPSOURCES:.cpp=.d) \
                    $(CSOURCES:.c=.d)

#force building the dependency files 
ifneq ($(findstring clean,$(MAKECMDGOALS)),clean)
include $(SOURCE_DEPENDENCIES)
endif

BASEOBJECTS=$(SOURCE_DEPENDENCIES:.d=.o)

CXXFLAGS+= -g -I . 

#rule to link the ta program 
ta: $(BASEOBJECTS)
	@echo "base objects are: $(BASEOBJECTS)" 
	$(CXX) -o $@ $(BASEOBJECTS) 


#rules to extract dependency files
%.d: %.cpp
	@echo "CXX CXXFLAGS -M $< > $@"
	@$(CXX) $(CXXFLAGS) -M $< > $@

%.d: %.C
	@echo "CXX CXXFLAGS -M $< > $@"
	@$(CXX) $(CXXFLAGS) -M $< > $@



#rules to make object files from c/cplusplus code
%.o: %.cpp %.d
	@echo "CXX CXXFLAGS -c -o $@ $<"
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.c %.d
	@echo "CXX CXXFLAGS -c -o $@ $<"
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

clean: 
	@rm -rf *.o *.d *.so *.a ta
