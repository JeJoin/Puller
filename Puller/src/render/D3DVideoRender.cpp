
#include <render/D3DVideoRender.h>
#include <common/imgutils.h>

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_TEX1)

struct D3dCustomVertex {
    float x, y, z;
    float u, v;
};

D3DVideoRender::D3DVideoRender()
    : m_bOpen(false)
    , m_hwnd(NULL)
    , m_iWidth(0), m_iHeight(0)
    , m_pIDirect3D9(NULL), m_pD3DDevice(NULL)
    , m_pTexture(NULL), m_pVertexBuffer(NULL)
{

}

D3DVideoRender::~D3DVideoRender()
{

}

int32_t D3DVideoRender::Open(int32_t width, int32_t height, const void * hwnd)
{
    if (hwnd == NULL || width <= 0 || height <= 0) {
        return -1;
    }

    m_hwnd = (HWND)hwnd;
    
    D3DPRESENT_PARAMETERS d3dParams = {}; // fix warning of init d3dParams
    m_pIDirect3D9 = Direct3DCreate9(D3D_SDK_VERSION);
    if (m_pIDirect3D9 == NULL) {
        goto fault;
    }

    d3dParams.Windowed   = TRUE;
    d3dParams.SwapEffect = D3DSWAPEFFECT_COPY;

    IDirect3DDevice9 * pD3DDevice = NULL;
    if (m_pIDirect3D9->CreateDevice(D3DADAPTER_DEFAULT,
                                    D3DDEVTYPE_HAL,
                                    m_hwnd,
                                    D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                    &d3dParams,
                                    &pD3DDevice) != D3D_OK) {
        goto fault;
    }

    m_pD3DDevice = pD3DDevice;
    pD3DDevice->Release();
    ////校验硬件顶点运算  
    //D3DCAPS9 caps;
    //m_pIDirect3D9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

    //int vp = 0;
    //if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
    //    vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
    //else
    //    vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

    IDirect3DVertexBuffer9* pVertexBuffer;
    const int kRectVertices = 4;
    if (m_pD3DDevice->CreateVertexBuffer(kRectVertices * sizeof(D3dCustomVertex),
                                       0,
                                       D3DFVF_CUSTOMVERTEX,
                                       //vp,
                                       D3DPOOL_MANAGED,
                                       &pVertexBuffer,
                                       NULL) != D3D_OK) {

        goto fault;
    }
    m_pVertexBuffer = pVertexBuffer;
    pVertexBuffer->Release();

    pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    pD3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
    _Resize(width, height);

    pD3DDevice->Present(NULL, NULL, NULL, NULL);

    m_bOpen = true;
    return 0;

fault:
    _Destroy();
    return -1;
}

int32_t D3DVideoRender::Start()
{
    return 0;
}

int32_t D3DVideoRender::Stop()
{
    return 0;
}

int32_t D3DVideoRender::Close()
{
    return 0;
}

int32_t D3DVideoRender::Render(int32_t w, int32_t h, uint8_t* data, int32_t size)
{
    if (w <= 0 || h <= 0 || data == NULL || size <= 0) {
        return -1;
    }

    if (m_iWidth != w || m_iHeight != h) {
        _Resize(w, h);
    }

    D3DLOCKED_RECT lockRect;
    if (m_pTexture->LockRect(0, &lockRect, NULL, 0) != D3D_OK) {
        return -1;
    }
    I420ToARGB(data, (uint8_t*)lockRect.pBits, w, h);

    m_pTexture->UnlockRect(0);

    m_pD3DDevice->BeginScene();
    m_pD3DDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
    m_pD3DDevice->SetStreamSource(0, m_pVertexBuffer, 0, sizeof(D3dCustomVertex));
    m_pD3DDevice->SetTexture(0, m_pTexture);
    m_pD3DDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
    m_pD3DDevice->EndScene();

    m_pD3DDevice->Present(NULL, NULL, NULL, NULL);

    return 0;
}

int32_t D3DVideoRender::_Destroy()
{
    m_pTexture = NULL;
    m_pVertexBuffer = NULL;
    m_pD3DDevice = NULL;
    m_pIDirect3D9 = NULL;
    m_hwnd = NULL;
    return 0;
}

int32_t D3DVideoRender::_Resize(int32_t w, int32_t h)
{
    m_iWidth  = w;
    m_iHeight = h;
    IDirect3DTexture9 * pTexture;

    m_pD3DDevice->CreateTexture(static_cast<UINT>(m_iWidth),
                                static_cast<UINT>(m_iHeight),
                                1,
                                0,
                                D3DFMT_A8R8G8B8,
                                D3DPOOL_MANAGED,
                                &pTexture,
                                NULL);
    m_pTexture = pTexture;
    pTexture->Release();

    // Vertices for the video frame to be rendered to.
    static const D3dCustomVertex rect[] = {
        { -1.0f, -1.0f, 0.0f, 0.0f, 1.0f },
        { -1.0f, 1.0f, 0.0f, 0.0f, 0.0f },
        { 1.0f, -1.0f, 0.0f, 1.0f, 1.0f },
        { 1.0f, 1.0f, 0.0f, 1.0f, 0.0f },
    };

    void* pBufData;
    if (m_pVertexBuffer->Lock(0, 0, &pBufData, 0) != D3D_OK) {
        return -1;
    }

    memcpy(pBufData, &rect, sizeof(rect));
    m_pVertexBuffer->Unlock();
    return 0;
}