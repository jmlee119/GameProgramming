# 수정사항

### Use CSS Framework 🎨🖌
>[Bootstrap](https://getbootstrap.kr/) | [Bulma](https://bulma.io/) | [Foundation](https://get.foundation/)
 
 
 
  #### *Bootstrap의 h1 을 수정* 
  * 기본값 
     ```html
    h1, h2, h3, h4, h5, h6, .h1, .h2, .h3, .h4, .h5, .h6 {
      margin-bottom: 0.5rem;
      font-weight: 500;
      line-height: 1.2; } 
  ```
  
  * 수정 
      ``` html  
         h1, h2, h3, h4, h5, h6, .h1, .h2, .h3, .h4, .h5, .h6 {
          margin-bottom: 0.5rem;
          font-weight: 500;
          line-height: 1.2;
          text-align: center; }
```

 #### *bulma의 Hero 추가 
    ```html
        <div class="hero">
\
              ...
    ```

#### *foundation 의 table 수정 
```html

*기본 
``` html

table {
  border-collapse: collapse;
  width: 100%;
  margin-bottom: 1rem;
  border-radius: 0; }
  thead,
  tbody,
  tfoot {
    border: 1px solid #ae225a;
    background-color: #94923b; }
  caption {
    padding: 0.5rem 0.625rem 0.625rem;
    font-weight: bold; }
  thead {
    background: #f8f8f8;
    color: #0a0a0a; }
  tfoot {
    background: #f1f1f1;
    color: #0a0a0a; }
  thead tr,
  tfoot tr {
    background: transparent; }
  thead th,
  thead td,
  tfoot th,
  tfoot td {
    padding: 0.5rem 0.625rem 0.625rem;
    font-weight: bold;
    text-align: left; }
  tbody th,
  tbody td {
    padding: 0.5rem 0.625rem 0.625rem; }
  tbody tr:nth-child(even) {
    border-bottom: 0;
    background-color: #f1f1f1; }
  table.unstriped tbody {
    background-color: #fefefe; }
    table.unstriped tbody tr {
      border-bottom: 1px solid #f1f1f1;
      background-color: #fefefe; }

@media print, screen and (max-width: 63.99875em) {
  table.stack thead {
    display: none; }
  table.stack tfoot {
    display: none; }
  table.stack tr,
  table.stack th,
  table.stack td {
    display: block; }
  table.stack td {
    border-top: 0; } }
```
수정
```html
table {
  border-collapse: collapse;
  
  margin-bottom: 1rem;
  border-radius: 0; }
  thead,
  tbody,
  tfoot {
    border: 1px solid #000000;
    background-color: #fce7e7; }
  caption {
    padding: 0.5rem 0.625rem 0.625rem;
    font-weight: bold; }
  thead {
    background: #f8f8f8;
    color: #0a0a0a; }
  tfoot {
    background: #f1f1f1;
    color: #0a0a0a; }
  thead tr,
  tfoot tr {
    background: transparent; }
  thead th,
  thead td,
  tfoot th,
  tfoot td {
    padding: 0.5rem 0.625rem 0.625rem;
    font-weight: bold;
    text-align: left; }
  tbody th,
  tbody td {
    padding: 0.5rem 0.625rem 0.625rem; }
  tbody tr:nth-child(even) {
    border-bottom: 0;
    background-color: #fcc0c0; }
  table.unstriped tbody {
    background-color: #fefefe; }
    table.unstriped tbody tr {
      border-bottom: 1px solid #f1f1f1;
      background-color: #fefefe; }


```
