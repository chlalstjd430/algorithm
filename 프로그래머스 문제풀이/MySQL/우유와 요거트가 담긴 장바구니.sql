-- 코드를 입력하세요
SELECT c1.CART_ID 
FROM CART_PRODUCTS AS c1 ,
    (SELECT CART_ID FROM CART_PRODUCTS WHERE NAME = "우유") AS c2
    WHERE c1.CART_ID = c2.CART_ID AND c1.NAME = "요거트"
