#include "WiFiManagerDesign.h"

WiFiManagerDesign::WiFiManagerDesign(WiFiManager *wifiManager)
{
    _fileServer = new AsyncWebServer(8080);
    _fileServer->on("/bg.jpg", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/bg.jpg");
    });
    _fileServer->begin();

    _wifiManager = wifiManager;
    _wifiManager->setCustomHeadElement(R"rawliteral(
        <style>
            :root {
                --violet: #785DFF;
                --violet-hover: #6B3AFF;
                --grey: #6c757d;
                --grey-hover: #5c636a;
            }
            body {
                background: url(http://192.168.4.1:8080/bg.jpg) no-repeat center center fixed; 
                -webkit-background-size: cover;
                -moz-background-size: cover;
                -o-background-size: cover;
                background-size: cover;
                font-family: 'Nunito', sans-serif;
            }
            h1 {
                margin-top: 0;
                margin-bottom: 1em;
            }
            body > div {
                display: none;
                opacity: 0.75;
                font-weight: 800;
                border: 0px;
                border-radius: 1.25rem;
                background-color: #fff;
                padding: 2em;
                margin: 0;
                position: absolute;
                top: 50%;
                left: 50%;
                -ms-transform: translate(-50%, -50%);
                transform: translate(-50%, -50%);
                min-width: 344px !important;
            }
            button {
                cursor: pointer;
                background-color: var(--violet);
                border-color:  var(--violet);
            }
            button:hover {
                background-color: var(--violet-hover);
                border-color:  var(--violet-hover);
            }
            input {
                margin-top: 1em;
            }
            dt {
                float: left;
                margin-right: 1em;
                color: #785DFF;
            }
            dd {
                
            }
            .btn-return {
                margin-top: 1em;
                background-color: var(--grey);
                border-color: var(--grey);
            }
            .btn-return:hover {
                background-color: var(--grey-hover);
                border-color: var(--grey-hover);
            }
            .c {
                margin-bottom: 2em;
            }
        </style>
        <script>
            window.onload = function(event) {
                document.title = "Configuration du WiFi";

                // Accueil
                if(!window.location.href.includes("/wifi") && !window.location.href.includes("/0wifi")) {
                    document.querySelector("body > div > form:nth-child(3) > button").innerText = "Configuration du WiFi";
                    document.querySelector("body > div > form:nth-child(5) > button").innerText = "Configuration du WiFi (sans scanner)";
                    document.querySelector("body > div > form:nth-child(7) > button").innerText = "Informations";
                    document.querySelector("body > div > form:nth-child(9) > button").innerText = "R&eacute;initialiser";
                    document.querySelector("body > div > h3").remove();
                }

                // Scan
                if(window.location.href.includes("/wifi") || window.location.href.includes("/0wifi")) {
                    let form = document.querySelector("body > div > form");
                    document.getElementById("p").setAttribute("placeholder", "Mot de passe");
                    let btnSave = document.querySelector("body > div > form > button");
                    btnSave.innerText = "Sauvegarder";
                    let btnScan = document.querySelector("body > div > div.c");
                    document.querySelector("body > div > div.c > a").innerText = "Scanner";
                    let copyBtnScan = btnScan.cloneNode(true);
                    btnScan.remove();
                    form.append(copyBtnScan);
                    let copyBtnSave = btnSave.cloneNode(true);
                    btnSave.remove();
                    form.append(copyBtnSave);

                // Add the return button
                    let btnReturn = document.createElement("button");
                    btnReturn.innerText = "Retour";
                    btnReturn.className = "btn-return"
                    btnReturn.addEventListener('click', function (event) {
                        event.preventDefault();
                        event.stopPropagation();
                        window.location.href = window.location.origin;
                    });
                    form.append(btnReturn);
                        const brList = document.querySelectorAll('br');
                        brList.forEach(br => {
                        br.remove();
                    });
                }

                document.querySelector("body > div").style.display = 'block';
            };
        </script>
    )rawliteral");
}