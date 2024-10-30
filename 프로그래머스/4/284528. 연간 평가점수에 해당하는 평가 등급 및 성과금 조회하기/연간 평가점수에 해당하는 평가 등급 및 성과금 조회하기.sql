-- 사번, 성명, 평가 등급, 성과금을 조회하는 SQL문
SELECT E.EMP_NO, EMP_NAME,
    CASE 
        WHEN AVG_SCORE >= 96 THEN "S"
        WHEN AVG_SCORE >= 90 THEN "A"
        WHEN AVG_SCORE >= 80 THEN "B"
        ELSE "C"
    END AS GRADE,
    CASE 
        WHEN AVG_SCORE >= 96 THEN SAL*0.2
        WHEN AVG_SCORE >= 90 THEN SAL*0.15
        WHEN AVG_SCORE >= 80 THEN SAL*0.1
        ELSE 0
    END AS BONUS
FROM (
    SELECT EMP_NO, AVG(IFNULL(SCORE,0)) AS AVG_SCORE
    FROM HR_GRADE 
    GROUP BY EMP_NO) AS G 
    JOIN HR_EMPLOYEES AS E ON E.EMP_NO = G.EMP_NO
ORDER BY EMP_NO ASC