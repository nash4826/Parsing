## Parsing

> 언어별 Parsing 연습

- JSON 파일을 각 언어를 활용하여 파싱한다.

- 다소 어려운 주제인 만큼 활용예제를 참고하여 이해해보자.

> JSON이란?

- JSON이란 JavaScript Object Notation 의 줄임말이다.

- 웹 언어의 javascript의 데이터 객체를 표현하는 방식/언어이다.

- 간결하기 때문에 기계나 사람 모두가 이해하기 편하다.

- 데이터 용량이 적고 Code로의 전환이 쉽다 는 장점이 있어서 XML을 대체하여 활용되고 있다.

> XML 이란?

- eXtensible Markup Language 의 줄임말이다.

- HTML과 매우 비슷한 문자 기반의 마크업 언어이다.

- 사람과 기계가 동시에 읽기 편한 구조로 되어 있다.


> JSON과 XML의 공통점

<ol>
  <li>둘 다 데이터를 저장하고 전달하기 위해 고안되었다.</li>
  <li>둘 다 기계뿐만 아니라 사람도 쉽게 읽을 수 있다.</li>
  <li>둘 다 계층적인 데이터 구조를 가진다.</li>
  <li>둘 다 다양한 프로그래밍 언어에 의해 파싱될 수 있다.</li>
  <li>둘 다 XMLHttpRequest 객체를 이용하여 서버로부터 데이터를 전송받을 수 있다.</li>
</ol>

> XMLHttpRequest 객체

- XMLHttpRequest 객체는 서버로부터 XML 데이터를 전송받아 처리하는 데 사용된다.

- XMLHttpRequest 객체를 사용하면 웹 페이지가 전부 로딩된 후에도 서버에 데이터를 요청하거나 서버로부터 데이터를 전송받을 수 있다. 즉, 웹 페이지 전체를 다시 로딩하지 않고 일부분만을 갱신할 수 있게 된다.

> JSON과 XML의 차이점

<ol>
  <li>JSON은 종료 태그를 사용하지 않는다.</li>
  <li>JSON의 구문이 XML의 구문보다 더 짧다.</li>
  <li>JSON 데이터가 XML 데이터보다 더 빨리 읽고 쓸 수 있다.</li>
  <li>XML은 배열을 사용할 수 없지만, JSON은 배열을 사용할 수 있다.</li>
  <li>XML은 XML 파서로 파싱되며, JSON은 자바스크립트 표준 함수인 ```eval()``` 함수로 파싱된다.</li>
</ol>

- 출처 : TCPSCHOOL
