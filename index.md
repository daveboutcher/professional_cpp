---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: default
---

# Introduction

At [Ocient](http://www.ocient.com/) we hire C++ programmers, many of
them right out of college, many listing 
C++ as a proficiency on their CV.  New graduates have used C++ in a
*Datastructures and Algorithms* class, and have a basic understanding
of the differences between a
[std::map](http://en.cppreference.com/w/cpp/container/map) and
a
[std::unordered_map](http://en.cppreference.com/w/cpp/container/unordered_map)
and how an employee **is a** person, a person **has an** address, a
person **is a** mammal, and mammals **have a** sound.

What new C++ programmers have had less experience with is practically
applying the lessons of the [CPP Core
Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md),
and *why* you would want a move constructor, or *why* memory should be
managed by a smart pointer.

This site strives to provide a practical set of exercises in writing
good C++...Professional C++.  Learning styles vary widely, and this
site will never cover 1% of the content from books like [Effective Modern
C++](https://www.amazon.com/dp/1491903996/) or [Modern C++
Design](https://www.amazon.com/dp/0201704315/). 
Many programmers, however, learn by *doing*, not by reading.  This
site provides a set of exercises that will hopefully require a lot of
"doing".  If you can implement all the exercises here without
referring to [Stack Overflow](https://stackoverflow.com/), the
exercises are probably not challenging enough.

The goal should be to implement all the exercises...not just check the
solutions out from git....though you certainly have that option.

Finally, I am a big believer in open source.  Ideas, contributions,
criticism's, and the occasional compliment are welcome.  All of this
work; the pages, the code; are stored on [Github](https://github.com/)
and can be forked, cloned, and examined.  The work is licensed under a
Creative Commons Attribution license, so attribution should be
provided in any derivative works.

Let the exercises begin.

<ul>
  {% for post in site.posts reversed %}
    <li>
      <a href="{{ post.url }}">{{ post.title }}</a>
    </li>
  {% endfor %}
</ul>

<hr>
![Creative Commons
License](https://i.creativecommons.org/l/by/4.0/88x31.png)

This work is licensed under a [Creative Commons Attribution 4.0
International License](http://creativecommons.org/licenses/by/4.0/)
