---
title: NP complete problems
layout: post
categories: clrs
---

<i><b>Boolean Satisfiability:-</b></i>

Boolean Satisfiability problem is one of the NP-complete problems. This problem asks us to find weather a set of boolean values satisfy a boolean combinational circuit.

Boolean Combinational circuits are circuits which consits of logic gates(e.g OR,XOR,NOT,etc) and a set of input. The set of boolean inputs are passed through the circuit and generally outputs one boolean value.SAT problem asks us the find that set of inputs which give one as the output value.

The above problem is the circuit way of representing Boolean Satisfiability problem.Other forms of this equation are :-

1) 1-cnf-sat
2) 2-cnf-sat
3) 3-cnf-sat

out of all these 3 forms 3-cnf-sat problem is NP complete whereas the other two are solvable in polynomial time.

Before we discuss more about satisfiability problem we must understand what does "cnf" mean in the above terms.

CNF stands for conjuctive normal form. In this form we have n number of variables and  the formula consists of clauses each clause contains the specified number of boolean elements.

<b>1) 1-cnf-sat</b>

In this case each clause consists of 1 element.The general form of this equation is :-

f = x<sub>1</sub> ^ x<sub>2</sub> ^ ...

Solving for this case is simple as we just have to check if the negation of an element x and x both are present in the sat formula.

<b>2) 2-cnf-sat </b>

In this case each clause consists of 2 elements. The general form of this equation is:-

f = (x<sub>1</sub> v y<sub>1</sub>) ^ (x<sub>2</sub> v y<sub>2</sub>) ^ ...

Solving this kind of sat formula is a bit harder than 1 sat.

To solve such a problem we will construct a graph of 2n vertices where n is the number of boolean elements.

We will draw an edge between 
1) &#172;x<sub>i</sub> and y<sub>i</sub>
1) &#172;y<sub>i</sub> and x<sub>i</sub>

if both the negation and the variable itself are in the same Strongly Connected Component of graph then it is not satisfiable.This can be done efficiently using Kosaraju's algorithm for strongly connected components.


