;---------------------B2D.INC-------------------------
;=====================================================
;"W"yazmac�ndaki 0..255 aras� ikili d�zendeki say�n�n, 
;y�zler,onlar ve birler basamaklar�ndaki rakamlar�n� 
;ay�rmada kullan�lan rutin.Bu rutin �a��r�lmadan �nce 
;basamaklar�na ay�r�lacak say� "W" yazmac�na y�klenmi� 
;olmal�d�r.
;=====================================================


;-----------------------------------------------------
b2d
	movwf	SAYI		
	clrf	YUZLER
	clrf	ONLAR
	clrf	BIRLER
	
YuzB
	movlw	.100
	subwf	SAYI,W   	
	btfsc	STATUS,C   	
	goto	YuzlerBasamagi
	
OnB
	movlw	.10
	subwf	SAYI,W
	btfsc	STATUS,C
	goto	OnlarBasamagi

	movf	SAYI,W
	movwf	BIRLER

	return
;-----------------------------------------------------
YuzlerBasamagi	
	incf	YUZLER,1	
	movwf	SAYI
	goto	YuzB
;-----------------------------------------------------
OnlarBasamagi	
	incf	ONLAR,1		
	movwf	SAYI
	goto	OnB
;=====================================================
