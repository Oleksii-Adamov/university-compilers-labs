#ifndef DRIVER_HH
# define DRIVER_HH
# include <string>
# include "ASTNode.hh"
# include "parser.hh"

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
  yy::parser::symbol_type yylex (driver& drv)
// ... and declare it for the parser's sake.
YY_DECL;

// Conducting the whole scanning and parsing of Calc++.
class driver
{
public:
    ASTNode* result = nullptr;

    // The name of the file being parsed.
    std::string file;

    // Whether to generate parser debug traces.
    bool trace_parsing;

    // Whether to generate scanner debug traces.
    bool trace_scanning;

    // The token's location used by the scanner.
    yy::location location;

    driver ();
    ~driver();

    // Run the parser on file F.  Return 0 on success.
    int parse (const std::string& f);

    // Handling the scanner.
    void scan_begin ();
    void scan_end ();



};
#endif // ! DRIVER_HH
